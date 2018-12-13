# SimBenchmark

SimBenchmark is a project providing the reliable benchmark results of state-of-the-art physics engines used for contact simulation for various robotic tasks.

We evaluated the most widely-used physics engines for robotics and machine learning applications. 
The list of the engines is as follows:

- RaiSim (Jemin Hwangbo, Dongho Kang et al.)
	- [What is RaiSim?](https://leggedrobotics.github.io/SimBenchmark/about/sims.html#RaiSim)
- [Bullet Physics](http://bulletphysics.org/)
- [Open Dynamics Engine](http://www.ode.org/)
- [Multi-Joint dynamics with Contact (a.k.a. MuJoCo)](http://mujoco.org/)
- [DART Sim](https://dartsim.github.io/)

You can see the details in [webpage](https://leggedrobotics.github.io/SimBenchmark/).

![ANYmal PD Control Benchmark](https://leggedrobotics.github.io/SimBenchmark/about/anymal.gif)

## Installation

SimBenchmark runs on Ubuntu 16.04 LTS.  

Notes:
- RaiSim and MuJoCo is proprietary. 
- Matlab R2018a is required for plotting (optional). 

### via Docker (recommended)

See [docker/README.md](https://github.com/leggedrobotics/SimBenchmark/blob/master/docker/README.md)

### via bash script 

- Put mjkey.txt in ```res/mujoco``` for MuJoCo
- Create CMakeLists.txt in ```res/raiSim``` for raiSim (read ```res/raiSim/README.md``` for details)
- Run install.sh script by ```./run_build.sh ```

## Test and Results

We designed the following tests for the evaluation 
- Rolling test: friction model test
- Bouncing test: single-body elastic collision test
- 666 balls test: single-body hard contact test
- Elastic 666 balls test: single-body energy test
- ANYmal PD control test: articulated-robot-system speed test for quadrupedal robot
- Atlas PD control test: articulated-robot-system speed test for bipedal robot
- ANYmal momentum test: articulated-robot-system momentum test
- ANYmal energy test: articulated-robot-system energy test

Please see [our webpage](https://leggedrobotics.github.io/SimBenchmark/) for more details. 

<!-- ## Citation

If you want to refer the benchmark result in an academic publication, please consider citing as 
 -->
## Contact

- Note that this benchmark is done by Dongho Kang and Jemin Hwangho who are the developers of RaiSim.
- If you have any concern, please contact [Dongho Kang](mailto:kangd@ethz.ch)
