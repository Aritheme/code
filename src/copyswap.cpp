/**************************************************
   > File Name:copyswap.cpp
   > Author: arith
   > Created Time:2022年01月02日 星期日 22时30分45秒
**************************************************/
#include<iostream>
#include<cstring>
#include "../headers/copyswap.h"
SampleCopySwap::SampleCopySwap(int n1, int nInc, int nSize)
    : m_nSize(nSize)
    , m_pData(nSize ? new int[nSize]:nullptr) 
{
    for(int ii =0;ii<nSize;++ii)
    {
        m_pData[ii]=n1+ii*nInc;
    }
}

SampleCopySwap::SampleCopySwap(const SampleCopySwap& obj)
    :m_pData(obj.m_nSize ? new int[obj.m_nSize]:nullptr) 
{
    m_nSize=obj.m_nSize;
    memmove(m_pData,obj.m_pData, m_nSize*sizeof(int));
}

SampleCopySwap& SampleCopySwap::operator=(SampleCopySwap obj)
{
    swap(*this,obj);
    return *this;
}

void swap(SampleCopySwap& lhs,SampleCopySwap& rhs)
{
    using std::swap;
    swap(lhs.m_nSize,rhs.m_nSize);
    swap(lhs.m_pData,rhs.m_pData);
}
void SampleCopySwap::print()
{
    using namespace std;
    for(int ii =0;ii<m_nSize;++ii)
    {
        cout<<m_pData[ii]<<" ";
    }
}

