#include <cmath>
#include <string>
#include <vector>

using namespace std;

// TODO find out what cpp equivalent is of vec
double norm(vec) {
    /*
    Return the norm of a vector stored as a dictionary,
    as described in the instructions.
    */

    double sumOfSquares = 0.0;
    for (int i = 0; i < vec.length; i++) {
        sumOfSquares += vec[x] * vec[x];
    }

    return sqrt(sumOfSquares);
}

// TODO find out what cpp equivalent is of vec
double cosineSimilarity(vec1, vec2) {
    /*
    Return the cosine similarity of sparse vectors vec1 and vec2,
    stored as dictionaries as described in the handout for Project 2.
    */

    dotProduct = 0.0; // floating point to handle large numbers
    for (int i = 0; i < vec1.length; i++) {
        if () {     // TODO if vec1[i] in vec2 
            dotProduct += vec1[x] * vec2[x];
        }
    }

    return dotProduct / (norm(vec1) * norm(vec2));
}

void getSentenceLists(string text) {

}

void getSentenceListFromFiles(vector<string> sentences) {

}

dictionary buildSemanticDescriptors(vector<string> sentences) {
    dictionary d;

    return d;
}

string mostSimilarWord(string word, vector<string> choices, dictionary semanticDescriptions) {

    return wordMostSimilar;
}

double runSimilarityTest(string fileName, dictionary semanticDescriptions) {

    return accuracy;
}