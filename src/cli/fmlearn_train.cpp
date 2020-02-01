//
// Created by naihai on 2020/1/29.
// main entry for fmlearn train in command line

#include "common/log.h"
#include "core/model.h"
#include "data/data.h"

#include "cli/cmdline.h"

int main(int argc, char* argv[]) {
  Logging::SetLevel(0);
  CmdLine cmd_line;
  cmd_line.SetTrain();

  if (cmd_line.Parse(argc, argv)) {
    // 构造DMatrix
    CliTrainParam * param = cmd_line.GetCliParam()->GetTrainParam();
    Logging::info(param->to_string());
    DMatrix* train_data = new DMatrix(param->train_file, true);
    int n_features = train_data->GetNumFeatures();
    // std::cout << n_features << std::endl;

    auto fm = new FactorizationMachine(param->task,
                                        n_features,
                                        param->n_factors,
                                        param->learning_rate,
                                        param->reg_w0,
                                        param->reg_W,
                                        param->reg_V,
                                        param->init_mean,
                                        param->init_stddev,
                                        param->norm,
                                        !param->quiet);
    // fit
    fm->Initialize();
    fm->Fit(train_data, param->n_epoch);
    // save model
    fm->GetModel()->Save(param->model_file);
  } else {
    Logging::error("FMLearn command line parameter parse failed");
    exit(1);
  }

  return 0;
}