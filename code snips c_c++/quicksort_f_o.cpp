#include <algorithm>

template<typename T, typename S = std::less<T> >
void qs (T *a, size_t leng) 
{
  if (leng < 2) return;
 
  const T& pivot = a[leng / 2];
 
  size_t i, j;
  for (i = 0, j = leng - 1; ; i++, j--) 
  {
    while (S(a[i], pivot)) i++;
    while (!S(a[j], pivot)) j--;
    
    if (i >= j) break;
    
    std::swap(a[i], a[j]);
  }
 
  qs(a, i);
  qs(a + i, leng - i);
}