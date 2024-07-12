extern void update_vector();
extern int bootstrap();
int main()
{       update_vector();
	bootstrap();
	asm volatile("ecall");
	return 0;
}

