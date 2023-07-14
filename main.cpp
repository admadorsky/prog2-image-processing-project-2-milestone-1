#include <iostream>
#include <tuple>
#include "tga_file.h"
using namespace std ;

int main() {
    int blue = 0 ;
    int green = 1 ;
    int red = 2 ;

    // read all files in the input/ folder
    tga_file car ;
    car.ReadTGAFile("./input/car.tga") ;
    tga_file circles ;
    circles.ReadTGAFile("./input/circles.tga") ;
    tga_file layer1 ;
    layer1.ReadTGAFile("./input/layer1.tga") ;
    tga_file layer2 ;
    layer2.ReadTGAFile("./input/layer2.tga") ;
    tga_file layer_blue ;
    layer_blue.ReadTGAFile("./input/layer_blue.tga") ;
    tga_file layer_green ;
    layer_green.ReadTGAFile("./input/layer_green.tga") ;
    tga_file layer_red ;
    layer_red.ReadTGAFile("./input/layer_red.tga") ;
    tga_file pattern1 ;
    pattern1.ReadTGAFile("./input/pattern1.tga") ;
    tga_file pattern2 ;
    pattern2.ReadTGAFile("./input/pattern2.tga") ;
    tga_file text ;
    text.ReadTGAFile("./input/text.tga") ;
    tga_file text2 ;
    text2.ReadTGAFile("./input/text2.tga") ;

    // part 01
    tga_file multiplied ;
    multiplied = layer1.Multiply(pattern1) ;
    multiplied.WriteTGAFile("./output/part1.tga") ;

    // part 02
    tga_file subtracted ;
    subtracted = layer2.Subtract(car) ;
    subtracted.WriteTGAFile("./output/part2.tga") ;

    // part 03
    tga_file multiplied2 ;
    tga_file screened ;
    multiplied2 = layer1.Multiply(pattern2) ;
    screened = multiplied2.Screen(text) ;
    screened.WriteTGAFile("./output/part3.tga") ;

    // part 04
    tga_file multiplied3 ;
    tga_file subtracted2 ;
    multiplied3 = layer2.Multiply(circles) ;
    subtracted2 = pattern2.Subtract(multiplied3) ;
    subtracted2.WriteTGAFile("./output/part4.tga") ;

    // part 05
    tga_file overlayed ;
    overlayed = layer1.Overlay(pattern1) ;
    overlayed.WriteTGAFile("./output/part5.tga") ;

    // part 06
    tga_file added ;
    added = car.AddByChannel(200, green) ;
    added.WriteTGAFile("./output/part6.tga") ;

    // part 07
    tga_file multiplied4 ;
    multiplied4 = car.MultiplyByChannel(4, red) ;
    multiplied4 = multiplied4.MultiplyByChannel(0, blue) ;
    multiplied4.WriteTGAFile("./output/part7.tga") ;

    // part 08
    tuple<tga_file, tga_file, tga_file> output_channels = car.SeparateChannels() ;

    tga_file blue_channel = get<0>(output_channels) ;
    tga_file green_channel = get<1>(output_channels) ;
    tga_file red_channel = get<2>(output_channels) ;

    red_channel.WriteTGAFile("./output/part8_r.tga") ;
    green_channel.WriteTGAFile("./output/part8_g.tga") ;
    blue_channel.WriteTGAFile("./output/part8_b.tga") ;

    // part 09
    tga_file combined ;
    tuple<tga_file, tga_file, tga_file> input_channels = {layer_blue, layer_green, layer_red};
    combined.CombineChannels(input_channels) ;
    combined.WriteTGAFile("./output/part9.tga") ;

    // part 10
    tga_file flipped ;
    flipped = text2.FlipImage() ;
    flipped.WriteTGAFile("./output/part10.tga") ;

    return 0 ;
}