//
// Created by Hsim_WONG on 2018/9/10.
//

#ifndef BACKEND_MATRIX_H
#define BACKEND_MATRIX_H

template<typename Object>
class matrix {
private:
    vector<vector<Object>> array;
public:
    matrix(int rows, int cols):array(rows);

};


#endif //BACKEND_MATRIX_H
