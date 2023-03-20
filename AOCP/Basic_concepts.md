
## Euclid's Algo

E0. if m \< n then m \<- n -\> m;
E1. Divide m by n and r is the remainder (where 0 \<= r < n)
E2. If r == 0 then the algorithm terminates; n is the result
E3. Set m \<- n, n \<- r, goto E1

### gotobased-C:

```c
int
Euclid(int m, int n)
{ E1:
  r = m%n;
  if (r > 0) goto E3;
  E2:
  return n;
  E3:
  m = n;
  n = r;
  goto E1;
}
```
### in C:
```c
int
Euclid(int m, int n)
{ int r;
  if (m < n) {m=m^n;n=m^n;m=m^n;}
  do
  {
  r = m%n;
  m = n;
  n = r;
  } while (r > 0);
  return m;
}
```

## Computational Method

Let a CM be a quadruple (Q, I, Omeg, f), in which Q
is a set containing subsets I and Omeg, and f a function from
Q into itself. f should leave Omeg pointwise fixed;
that is, f(q) should equal q for all elements q of Omeg.
f: Q -\> Q
   q -\> { q if q in Omeg
        { s if q in I where s in Q\I or Omeg
        { x if q in Q\I or Omeg where x in Q\I or Omeg
An algorithm always reduces to a f(q) = q where q in Omeg

x in I defines a computation sequence:
    x0 = x and xk+1 = f(xk) for k \>= 0

Going back to Euclids algorithm:
Q is the set of all simpletons (n), all ordered pairs (m,n) and all
ordered quadruples (m,n,r,1), (m,n,r,2) and (m,n,r,3) where m and n are
positive integers and r is a non negative integer!
I is the subset of all pairs (m,n) and Omeg is the subset of all singletons (n)
Let f be
    f((m,n)) = (m,n,0,1);    f((n)) = (n);
    f((m,n,r,1)) = (m,n, modulo m n, 2);
    f((m,n,r,2)) = (n) if r = 0, (m,n,r,3) otherwise;
    f((m,n,p,3)) = (n,p,p,1).

# Exercises

algorithm for replacing (a b c d) with (b c d a)

S: t \<- m, m \<- n, n \<- t
S(m,n) = (m,n,m,1)
S() = ()
S(m,n,t,1) = S(n,n,t,2)
S(m,n,t,2) = S(n,t,t,3)
S(m,n,t,3) = ()

R1: S((a,b))
    (a-\>b,b-\>a,c-\>c,d-\>d)
R2: S((b,c))
    (a-\>b,b-\>c,c-\>a,d-\>d)
R3: S((a,d))
    (a-\>b,b-\>c,c-\>d,d-\>a)

