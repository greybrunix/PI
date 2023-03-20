#include <stdio.h>

void
func( int*px )
{
	*px += *px << 5;
}

int
main(   int argc,
	const char *argv[]  )
{
	int flag_err;
	int x;
	int *px;

	flag_err = 0;
	x = 10;
	px = &x;
	func( px );
	printf("%d\n", x);

	return flag_err;
}
