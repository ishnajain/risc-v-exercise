typedef struct{
	unsigned int  mepc, mstatus, ra, t0,
		 t1, t2, a0, a1, a2, a3,
		 a4, a5, a6, a7, t3, t4,
		 t5, t6, mcause, pad[5];
} context_frame_t;

void exception_handler(unsigned int mcause, context_frame_t* frame)
{
	if(mcause & (1<<31))	
		return;
	else
		frame->mepc+=(*(unsigned char*)frame->mepc)& 2 ? 4 : 2;
}

