#pragma once
class SampleCopySwap
{
    int m_nSize;
    int* m_pData;
public:
    SampleCopySwap(int n1, int nInc, int nSize);
    SampleCopySwap(const SampleCopySwap& obj);
    SampleCopySwap& operator=(SampleCopySwap obj);
    void print();
    friend void swap(SampleCopySwap& lhs,SampleCopySwap& rhs);
};
