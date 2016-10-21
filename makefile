stringtools: .c
	gcc  .c -o stringTests.out

run: mainTests
	./mainTests.out