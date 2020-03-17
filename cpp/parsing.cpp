#include "parsing.h"

void toLowerCase(string& w) {
    for (size_t i = 0; i < w.length(); i++) {
        w[i] = tolower(w[i]);
    }
}