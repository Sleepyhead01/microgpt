//MicroGPT.cpp
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <limits>
#include <set>

using namespace std;

//random generator //TODO: read more about 'Modern' rng & 'Traditional' rng
random_device rd;
mt19937 gen(rd());
void fiya_shuffle(vector<string>& input){
    uniform_int_distribution<int> distrib(0, size(input) - 1);
    for(int i = 0; i < size(input); i++){
        int random_num = distrib(gen);//TODO: I'm not sure know this is not mathematically correct but works for now
        swap(input[i], input[random_num]);
    }
}

// Let there be a Dataset `docs`: vector[str] of documents (e.g. a list of names)
// Note: avoiding download from a link functionality to reduce code bloat
vector<string> get_dataset(string path){
    ifstream inputFile(path);
    if(!inputFile.is_open()){
    cerr << "Error: Unable to open this file" << endl;
    return {};
    }

    vector<string> docs;
    string line;
    while(getline(inputFile, line)){
        if(size(line)> 0) docs.emplace_back(line);
    }

    //random shuffle the Dataset
    fiya_shuffle(docs);

    return docs;
}

//TODO: keeping the return type as string instead of char for now. 
vector<string> tokenize(vector<string>& docs){
    set<string> uchars_set;
    for(auto doc:docs){
        for(auto c:doc){
            string tok(1,c);
            uchars_set.insert(tok);
        }
    }

    return vector<string>(uchars_set.begin(), uchars_set.end());
}

int main(){
    // Let there be a Dataset `docs`: vector[str] of documents (e.g. a list of names)
    vector<string> docs = get_dataset("input.txt");
    cout << "num docs: " << size(docs) << endl;
    // for(auto x: docs){
    //     cout<<x<<endl;
    // }cout<<"-----\n";

    // Let there be a Tokenizer to translate strings to sequences of integers ("tokens") and back
    vector<string> uchars = tokenize(docs);
    int BOS = size(uchars) + 1;
    int vocab_size = size(uchars) + 1;
    cout << "vocab size: " << vocab_size << endl; 
    // for(auto x: uchars){
    //     cout<<x<<endl;
    // }cout<<"-----\n";

    

    return 0;
}