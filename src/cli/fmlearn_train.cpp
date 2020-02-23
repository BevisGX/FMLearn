//
// Created by naihai on 2020/1/29.
// main entry for fmlearn train in command line

#include <ctime>

#include "common/log.h"
#include "model/hyper_param.h"
#include "solver/solver.h"

#include "cli/cmdline.h"


int main(int argc, char* argv[]) {
  Logging::SetLevel(1);
  CmdLine cmd_line;
  cmd_line.SetTrain();

  if (cmd_line.Parse(argc, argv)) {
    HyperParam* param = cmd_line.GetParam();

    LogInfo(param->GetTrainParam()->to_string());

    Solver solver;
    solver.Initialize(param);
    solver.Start();
  } else {
    LogError("FMLearn command line parameter parse failed");
    exit(1);
  }

  return 0;
}