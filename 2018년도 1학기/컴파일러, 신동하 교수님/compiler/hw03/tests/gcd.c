/********************************/

int gcd(int u, int v)
{
  int g;
  if (v == 0)
    g = u;
  else
    g = gcd(v, u - u / v * v);
  return g;
}

/********************************/
