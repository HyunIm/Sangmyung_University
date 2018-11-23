// ======================================================================

int gcd(int u, int v)
{
  int g;

  if (v == 0)
    g = u;
  else
    g = gcd(v u - u / v * v);
  return g;
}

void main(void)
{
  int x;
  int y;
  int z;

  input x;
  input y;
  z = gcd(x, y);
  output z;
}

// ======================================================================
