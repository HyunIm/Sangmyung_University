// ======================================================================

void main(void)
{
  int i;
  int j;
  int k;

  i = 10;
  j = 999;
  k = 30;

  if (i < j)
    if (j < k)
      output k;
    else
      output j;
  else if (i < k)
    output k;
  else
    output i;
}

// ======================================================================
