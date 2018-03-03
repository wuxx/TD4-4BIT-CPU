#include <stdio.h>
#include <string.h>
#include <assert.h>

/* td4 assembly compiler */
/* may be the most stupid compiler in this world :( */

#define get_bit(x, bit_index) ((x >> bit_index) & 0x1)

typedef unsigned int u32;
typedef   signed int s32;

typedef unsigned short u16;
typedef   signed short s16;

typedef unsigned char u8;
typedef   signed char s8;

struct insn {
	char s[32];
	u8 code;
};

u32 iindex = 0;
struct insn insn_set[128];

s32 add_insn(char *s, u8 code)
{
	assert(iindex < (sizeof(insn_set) / sizeof(insn_set[0])));

	strncpy(insn_set[iindex].s, s, sizeof(insn_set[0].s));
	insn_set[iindex].code = code;

	iindex++;
	return 0;
};

struct insn * get_insn(char *s)
{
	u32 i;
	for(i = 0; i < iindex; i++) {
		if(strcmp(insn_set[i].s, s) == 0) {
			return &insn_set[i];
		}
	}

	return NULL;
}

void build_insn_set()
{
	u32 i;
	char s[32];
	u8 c, code;

	/* ADD A, Im */
	c = 0 << 4;
	for(i = 0; i < 16; i++) {
		snprintf(s, sizeof(s), "ADD A, 0x%X\n", i);
		code = c | i;
		add_insn(s, code);
	}
	

	/* MOV A, B */
	c = 1 << 4;
	snprintf(s, sizeof(s), "MOV A, B\n");
	code = c | 0;
	add_insn(s, code);

	/* IN A */
	c = 2 << 4;
	snprintf(s, sizeof(s), "IN A\n");
	code = c | 0;
	add_insn(s, code);


	/* MOV A, Im */
	c = 3 << 4;
	for(i = 0; i < 16; i++) {
		snprintf(s, sizeof(s), "MOV A, 0x%X\n", i);
		code = c | i;
		add_insn(s, code);
	}

	/* MOV B, A */
	c = 4 << 4;
	snprintf(s, sizeof(s), "MOV B, A\n");
	code = c | 0;
	add_insn(s, code);

	/* ADD B, Im */
	c = 5 << 4;
	for(i = 0; i < 16; i++) {
		snprintf(s, sizeof(s), "ADD B, 0x%X\n", i);
		code = c | i;
		add_insn(s, code);
	}


	/* IN B */
	c = 6 << 4;
	snprintf(s, sizeof(s), "IN B\n");
	code = c | 0;
	add_insn(s, code);

	/* MOV B, Im */
	c = 7 << 4;
	for(i = 0; i < 16; i++) {
		snprintf(s, sizeof(s), "MOV B, 0x%X\n", i);
		code = c | i;
		add_insn(s, code);
	}

	/* OUT B */
	c = 9 << 4;
	snprintf(s, sizeof(s), "OUT B\n");
	code = c | 0;
	add_insn(s, code);

	/* OUT Im */
	c = 11 << 4;
	for(i = 0; i < 16; i++) {
		snprintf(s, sizeof(s), "OUT 0x%X\n", i);
		code = c | i;
		add_insn(s, code);
	}

	/* JZ Im  */
	c = 14 << 4;
	for(i = 0; i < 16; i++) {
		snprintf(s, sizeof(s), "JZ 0x%X\n", i);
		code = c | i;
		add_insn(s, code);
	}

	/* JMP Im */
	c = 15 << 4;
	for(i = 0; i < 16; i++) {
		snprintf(s, sizeof(s), "JMP 0x%X\n", i);
		code = c | i;
		add_insn(s, code);
	}
	
}

int main(int argc, char **argv)
{
	s32 i;
	FILE *fp;
	char line[256];
	s32 l = 0;
	struct insn *pinsn;

	if (argc == 1) {
		fprintf(stderr, "%s xxx.s\n", argv[0]);
		return -1;
	}
	
	build_insn_set();

#if 0
	for(i = 0; i < iindex; i++) {
		printf("[%d]: {[%s], 0x%02x}\n", i, insn_set[i].s, insn_set[i].code);
	}
#endif

    	if ((fp = fopen(argv[1], "r")) == NULL) {
        	fprintf(stderr, "fopen fail!\n");
        	return -1;
    	}

    	fgets(line, sizeof(line), fp);
    	while(!feof(fp)) {

#if 0
        	printf("get [%s]\n", line);
#endif
		if (line[0] == '#') {
			l--;
			goto end;
		}


		if (l % 4 == 0) {
			printf("\n[%x]: ", l);
		}

		if ((pinsn = get_insn(line)) == NULL) {
			fprintf(stderr, "\nfailed on line %d: [%s]\n", l + 1, line);
			return -1;
		}

		for(i = 7; i >= 0; i--) {
			printf("%d", get_bit(pinsn->code, i));
		}

		printf(" ");

end:
        	memset(line, 0, sizeof(line));
		l++;
        	fgets(line, sizeof(line), fp);
    	}

	fclose(fp);

	return 0;
}
