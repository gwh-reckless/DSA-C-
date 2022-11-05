#pragma once

using Rank=int;

template <typename T> void merge(T*, Rank , Rank, Rank);
template <typename T>
void mergeSort(T* S, Rank lo, Rank hi) {
  if(hi - lo < 2) return;
  Rank mi = (hi + lo) >>1; 
  mergeSort(S,lo, mi);  mergeSort(S,mi,hi);
  merge(S,lo, mi, hi);
}

template <typename T>
void merge(T* S, Rank lo, Rank mi,Rank hi)
{
  Rank i = 0; T* A = S + lo;
  Rank j = 0, lb = mi -lo; T* B = new T[lb];
  for(Rank i = 0; i < lb; i++)  B[i] = A[i];  //  B: left half

  Rank k = 0, lc = hi - mi; T* C = S + mi; // C: right half
  while((j < lb) && (k < lc)) {
    A[i++] = (B[j] < C[k] ? B[j++] : C[k++]);
  }
  while( j < lb) {
    A[i++] = B[j++];
  }
  delete [] B;
}

