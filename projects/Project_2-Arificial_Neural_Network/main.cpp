#include "neuralNetwork.hpp"
#include "errno.h"

using namespace std;


int main() {
    string trainfilename, testfilename, initfilename, trainedfilename, outfilename;
    ifstream trainfile, testfile, initfile, trainedfile;
    ofstream outfile;

    double learningRate;
    int epoch;
    
    string s;
    
    cout << "train or test? ..." << endl << ">";
    cin >> s;

    if (s == "train" || s == "Train"){
        cout << "initial weight file (aka .init file)? " << endl << ">";
        cin >> initfilename;
        cout << ".train file? " << endl << ">";
        cin >> trainfilename;
        cout << "output filename? "<< endl << ">";
        cin >> outfilename;
        cout << "learning rate?" << endl << ">";
        cin >> learningRate;
        cout << "number of epochs?" << endl << ">";
        cin >> epoch;

        initfile.open(initfilename.c_str());
        trainfile.open(trainfilename.c_str());
        outfile.open(outfilename.c_str());

        if (initfile.is_open() && trainfile.is_open() && outfile.is_open()){
            neuralNetwork *test = new neuralNetwork(initfile);
            test -> train(trainfile, learningRate, epoch);
            test -> save(outfile);
        }
        else {
            fprintf(stderr, "Unable to open input (or output) files: %s", strerror(errno));
            return -1;
        }
    }

    else if (s == "test" || s == "Test"){

        cout << ".trained file?" << endl << ">";
        cin >> trainedfilename;
        cout << ".test file?" << endl << ">";
        cin >> testfilename;
        cout << "output filename?" << endl << ">";
        cin >> outfilename;

        trainedfile.open(trainedfilename.c_str());
        testfile.open(testfilename.c_str());
        outfile.open(outfilename.c_str());

        if (trainedfile.is_open() && testfile.is_open() && outfile.is_open()){
            neuralNetwork *test = new neuralNetwork(trainedfile);
            test -> test(testfile, outfile);
        }
        else {
            fprintf(stderr, "Unable to open input (or output) files: %s", strerror(errno));
            return -1;
        }
    }
    else {
        cout << "Invalid input, please try again!" << endl;
        return -1;
    }
    return 0;
}
