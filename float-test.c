float floatTest;
int test;

int round(float f)
{
  return (f>0)?(int)(f+0.5):(int)(f - 0.5);
}


task main()
{

while (true) {
	test = round(0.5);
}

}
