//
// Created by kakise on 6/10/18.
//

#ifndef IDMSIM_IDM_H
#define IDMSIM_IDM_H


class IDM {
public:
    IDM(float v0, float T, float s0, float a, float b);

    float a(float s, float v, float vl);

private:
    float m_v0, m_T, m_s0, m_a, m_b;
    int alpha_v0 = 1;
    int speedlimit = 1000;
    int speedmax = 1000;
    float bmax = 18;
    float noiseAcc = 0.3f;
};


#endif //IDMSIM_IDM_H
