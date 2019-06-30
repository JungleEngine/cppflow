//
// Created by sergio on 16/05/19.
//
#include <iostream>
#include "../../include/Model.h"
#include "../../include/Tensor.h"
#include <opencv2/opencv.hpp>
#include <numeric>
#include <iomanip>


int main(){
    Model model("../frozen_model.pb");
    auto outName = new Tensor(model, "output");
    auto inpName1 = new Tensor(model, "input_1");
    auto inpName2 = new Tensor(model, "input_2");
    auto inpName3 = new Tensor(model, "Placeholder_2");
    auto inpName4 = new Tensor(model, "Placeholder");

    cv::Mat img1;
    cv::Mat img2;
    cv::Mat inp1;
    cv::Mat inp2;

    img1 = cv::imread("/media/syrix/programms/projects/GP/Intelligent_Frame_Skipping/src/libs/cppflow/examples/coco/2201.png", CV_LOAD_IMAGE_COLOR);
   	int rows1 = img1.rows;
    int cols1 = img1.cols;

    img2 = cv::imread("/media/syrix/programms/projects/GP/Intelligent_Frame_Skipping/src/libs/cppflow/examples/coco/2201.png", CV_LOAD_IMAGE_COLOR);
   	int rows2 = img2.rows;
    int cols2 = img2.cols;



    cv::resize(img1, inp1, cv::Size(256, 256));
    cv::resize(img2, inp2, cv::Size(256, 256));

    cv::cvtColor(inp1, inp1, CV_BGR2RGB);
    cv::cvtColor(inp2, inp2, CV_BGR2RGB);

    cout<<"image height: "<<rows1<<std::endl;
    // std::vector<float > img1_data;
    // img1_data.assign(inp1.data, inp1.data + inp1.total() * inp1.channels());

    // std::vector<float > img2_data;
    // img2_data.assign(inp2.data, inp2.data + inp2.total() * inp2.channels());


    // inpName1->set_data(img1_data, {1, 256, 256, 3});
    // inpName2->set_data(img2_data, {1, 256, 256, 3});


    // std::vector<float > hold_prob;
    // hold_prob.push_back(1.0);
    // inpName3->set_data(hold_prob, {1});

    // std::vector<int> is_training;
    // is_training.push_back(1);
    // inpName4->set_data((bool)is_training, {1});



    // model.run({inpName1, inpName2, inpName3, inpName4}, outName);
    // std::cout<<"output: "<< outName->get_data<float>()[0] <<std::endl;

return 0;
}
