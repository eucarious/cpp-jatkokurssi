// turning long runtime into less runtime, more memory use
/*
  Harjoitus 1

  Optimoi sini-funktion käsittely. Älä muuta kääntäjäoptioita.
  Vertaa alkuperäistä ja optimoitua versiota: og = 1.9s

  - kuinka paljon enemmän muistia optimoitu versio kuluttaa? cant check, on vscode
  - kuinka paljon nopeammin optimoitu versio toimii?

*/
#include <cstdio>
#include <ctime>
#include <cmath>

#define DEG_TO_RAD(A) (A / 57.296)
#define ITERATIONS 1000000


int main()
{
  clock_t t1, t2;
  unsigned i, a;
  double val;
  
  t1 = clock();
  for (i = 0; i < ITERATIONS; ++i)
    {
      for (a = 0; a < 360; ++a)
	{
	  /*
	    OptimizeIt!
	  */
	  val = std::sin(DEG_TO_RAD(a));
	}
    }
  t2 = clock();
  printf("%.1fs\n", (t2 - t1) / (float)CLOCKS_PER_SEC);

  return 0;
}
