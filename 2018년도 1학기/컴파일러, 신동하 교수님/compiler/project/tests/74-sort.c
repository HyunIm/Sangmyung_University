// ======================================================================

int x[5];

int minloc(int a[], int low, int high)
{
  int i;
  int x;
  int k;

  k = low;
  x = a[low];
  i = low + 1;
  while (i < high) {
    if (a[i] < x) {
      x = a[i];
      k = i;
    } else;
    i = i + 1;
  }
  return k;
}

void sort(int a[], int low, int high)
{
  int i;
  int k;
  int t;

  i = low;
  while (i < high - 1) {
    k = minloc(a, i, high);
    t = a[k];
    a[k] = a[i];
    a[i] = t;
    i = i + 1;
  }
}

void main(void)
{
  int i;

  i = 0;
  while (i < 5) {
    input x[i];
    i = i + 1;
  }
  sort(x, 0, 5);
  i = 0;
  while (i < 5) {
    output x[i];
    i = i + 1;
  }
}

// ======================================================================
