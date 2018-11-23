// ======================================================================

int sum(int n)
{
  int tmp;

  if (n == 1)
    return 1;
  else {
    tmp = sum(n - 1));
    return n + tmp;
  }
}

void main(void)
{
  int i;
  int j;

  i = 100;
  j = sum(i);
  output j;
}

// ======================================================================
