#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NIL (void*) 0
#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; }\
                      while (0)
/* Auxiliary procedures */
unsigned long int
len(const char*src)
{ int ret = 0;
  while (*src)
  { ret++;
    src++;
  }
  return ret;
}

void
removeChar(char*s)
{ char *tmp = s+1;
  while (*tmp)
  { SWAP(*tmp, *s, char);
    s++; tmp++;
  }
  SWAP(*tmp,*s, char);
}

/* Exercise 4 */
int
bitsOne(unsigned int n)
{ int total = 0;
  do
  { if (n%2) total++;
    n >>= 1;
  } while (n);
  return total;
}


/* Exercise 5 */
int
trailing(unsigned int n, int size)
{ if (n%2 || !size) return 0;
  else return 1 + trailing(n>>1,size-1);
}
int
trailingZ(unsigned int n)
{ int total = trailing(n, sizeof n*8);
  return total;
}

/* Exercise 8 */
char*
cpy(char*dest, const char*src)
{ char* ret = dest;
  while (*src)
  { *dest = *src;
    src++; dest++;
  } *dest = '\0';
  return ret;
}


/* Exercise 7 */
char*
cat(char*dest, const char*src)
{ char *ret;
  int first_size = len(dest);
  ret = cpy(dest + first_size, src) -first_size;
  return ret;
}


/* Exercise 9 */
int
cmp(char*s1, char*s2)
{ int ret = 0;
  while (*s1 && *s2 && !ret)
  { if (*s1 > *s2) ret = 1;
    else if (*s1 < *s2) ret = -1;
    s1++; s2++;
  }
  if (!ret)
  { if (*s1) ret = 1;
    else if (*s2) ret = -1;
    else ret = 0;
  }

  return ret;
}


/* Exercise 10 */
char*
substr(char*s1,char*s2)
{ char* ret = s2;
  char* tmp = s1;
  int flag = (len(s1) == 0) &&(len(s2)==0)? 1: 0;
  while (*s1 && !flag)
  { while (*tmp && *tmp == *ret && *ret)
    { tmp++;
      ret++;
    }
    if (!*ret)
    { flag = 1;
      ret = s1;
    }
    else
    { tmp = ++s1;
      ret = s2;
      flag = 0;
    }
  }
  if (!flag) ret = NIL;
  return ret;
}


/* Exercise 11 */
void
reverse(char*s)
{ int i = len(s);
  char*rev = s+(i-1);
  i = i/2;
  while (i)
  { SWAP(*s,*rev, char);
    s++; rev--; i--;
  }
}


/* Exercise 12 */
int
isVow(char s)
{ int f = 0;
  if (s == 'a' || s == 'e' ||
      s == 'i' || s == 'o' ||
      s == 'u' || s == 'A' ||
      s == 'E' || s == 'I' ||
      s == 'O' || s == 'U')
    f = 1;
  return f;
}
void
remVow(char*s)
{ char *ret = s;
  while (*ret)
  { if (isVow(*ret))
      removeChar(ret);
    else ret++;
  }
}

void
truncW(char*s, int n)
{ int counter = 0;
  while (*s)
  { if (*s == 0x20)
    { counter = 0;
      s++;
    }
    else if (counter == n)
      removeChar(s);
    else
    { counter++;
      s++;
    }
  }
}

int
indexMax(int*arr, int N)
{ int max = 0;
  int i = 0;
  while (i < N)
  { if (arr[i] > arr[max]) max = i;
    i++;
  }
  return max;
}
char
mostFreq(char*s)
{ char res = 0x0;
  int counter[256];
  int i;
  for (i = 0; i < 256; i++) counter[i] = 0;
  while (*s)
  { counter[(int) *s]++;
    s++;
  }
  res = (char) indexMax(counter, 256);
  return res;
}

int
eq_conseq(char*s)
{ int counter = 0; int max = 0;
  char current = *s;
  if (current)
  { s++; max = counter = 1;
    while (*s)
    { if (*s != current)
      { counter = 1;
        current = *s;
      }
      else
      { counter++;
        if (counter > max)
          max = counter;
      }
      s++;
    }
  }
  return max;
}

int
difConsecutivos(char *s)
{ char lastSeenIn[256];
  int i;
  int startDif = -1;
  int maxDif = 0;

  for (i=0; i<256;i++)
    lastSeenIn[i] = -1;

  for(i = 0; s[i]; i++)
  { if (lastSeenIn[(int) s[i]] > startDif)
    { if((i - startDif - 1) > maxDif)
        maxDif = i - startDif - 1;
      startDif = lastSeenIn[(int) s[i]];
    }
    lastSeenIn[(int) s[i]] = i;
  }
	maxDif = maxDif > (i - startDif - 1) ? maxDif : (i - startDif -1);
  return maxDif;
}
int maiorPrefixo (char s1 [], char s2 [])
{ int count = 0;
  while (*s1 && *s2 && *s1++ == *s2++)
    count++;
  return count;
}
int maiorSufixo (char s1 [], char s2 [])
{ int count = 0;
  int i, j;
  i = len(s1)-1; j = len(s2)-1;
  while (i>=0 && j >= 0 && s1[i--] == s2[j--])
    count++;
  return count;
}
int sufPref (char s1[], char s2[])
{ int count = 0; int i, j = 0;
  for (i = 0; s1[i]; i++)
  { if (s1[i] == s2[j++]) count++;
    else count = j = 0;
  }
  return count;
}
int contaPal (char s[])
{ int count = 0; int flag = 0;
  while (*s)
  { if (!flag && *s != 0x20 && *s != 0x0a) flag = 1;
    if (flag == 1 && *s != 0x20 && *s != 0x0a)
    { count++;
      flag = 2;
    }
    if (*s==0x20 || *s==0x0a) flag = 0;
  s++;
  }
  return count;
}

int
countVow(char*s)
{ int res=0;
  while (*s)
  if (isVow(*s++))
    res++;
  return res;
}

int
contida(char*a,char*b)
{ int res = 1;
  int i, j;
  for (i=0;a[i] && res; i++)
  { for (j=0;b[j] && b[j] != a[i];j++);
    if (!b[j]) res = 0;
  }
  return res;
}
int
palindrome(char*s)
{ int res = 1;
  int i,j; int n = (int) len(s);
  i=j=n > 0 ? (n-1)/2: 0;
    if (!(n%2) && n != 0) j++;
  for (; i >= 0 && s[j] && res; i--, j++)
    if (s[i] != s[j]) res = 0;
  return res;
}
/* Main Procedure */
int
main(int argc,
     char**argv,
     char**envp)
{ printf("%d\n", palindrome("bbaaaabb"));
	return 0;
}
