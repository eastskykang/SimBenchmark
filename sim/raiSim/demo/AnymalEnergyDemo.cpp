//
// Created by kangd on 18.02.18.
//

#include <boost/program_options.hpp>

#include "raiSim/World_RG.hpp"
#include "raiCommon/utils/StopWatch.hpp"

//#define VIDEO_SAVE_MODE

namespace po = boost::program_options;
std::vector<double> kenergy;

void showplot(double);

int main(int argc, const char* argv[]) {

  std::string urdfPath(__FILE__);
  while (urdfPath.back() != '/')
    urdfPath.erase(urdfPath.size() - 1, 1);
  urdfPath += "../../../res/ANYmal-energy/robot.urdf";

  rai_sim::World_RG sim(800, 600, 0.5, rai_sim::NO_BACKGROUND);

  auto checkerboard = sim.addCheckerboard(2, 100, 100, 0.1, 1, -1, rai_sim::GRID);

  auto anymal = sim.addArticulatedSystem(urdfPath);
  anymal->setGeneralizedCoordinate(
      {0, 0, 10,
       1.0, 0.0, 0.0, 0.0,
       0.03, 0.4, -0.8,
       -0.03, 0.4, -0.8,
       0.03, -0.4, 0.8,
       -0.03, -0.4, 0.8});
  anymal->setGeneralizedVelocity(
      {0, 0, 0,
       0.2, 1.0, 0.5,
       0.0, 0.0, 0.0,
       0.0, 0.0, 0.0,
       0.0, 0.0, 0.0,
       0.0, 0.0, 0.0});

  double g = -0;
  double dt = 0.005;
  sim.setGravity({0, 0, g});

  sim.cameraFollowObject(checkerboard, {15.0, 0.0, 15.0});

  double E0 = anymal->getEnergy({0, 0, g});
  for(int i = 0; i < int(5.0/dt) && sim.visualizerLoop(dt, 1.0); i++) {
    sim.integrate(dt);
    kenergy.push_back(anymal->getEnergy({0, 0, g}));
  }

  showplot(E0);
  return 0;
}

void showplot(double E0) {

  int n = kenergy.size();
  Eigen::MatrixXd tdata(n, 1);
  Eigen::MatrixXd Edata(n, 1);
  Eigen::MatrixXd edata(n, 1);

  for(int i = 0; i < n; i++) {
    tdata(i, 0) = i;
    Edata(i, 0) = kenergy[i];
    edata(i, 0) = E0 - kenergy[i];
  }

  rai::Utils::Graph::FigProp2D figure1properties("step", "Energy", "Energy");
  rai::Utils::graph->figure(1, figure1properties);
  rai::Utils::graph->appendData(1,
                                tdata.data(),
                                Edata.data(),
                                n,
                                "E");
  rai::Utils::graph->drawFigure(1);

  rai::Utils::Graph::FigProp2D figure2properties("step", "Energy error", "Energy error");
  rai::Utils::graph->figure(2, figure2properties);
  rai::Utils::graph->appendData(2,
                                tdata.data(),
                                edata.data(),
                                n,
                                "error");
  rai::Utils::graph->drawFigure(2);
  rai::Utils::graph->waitForEnter();
}
