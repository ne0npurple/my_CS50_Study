    int I[4]={1,2,3,4};
    int *i = I;
    printf("%p => %d\n", i+0, *(i+0));
    printf("%p => %d\n", i+1, *(i+1));
    printf("%p => %d\n", i+2, *(i+2));
    printf("%p => %d\n", i+3, *(i+3));

    printf("%p => %d\n", I+0, *(I+0));
    printf("%p => %d\n", I+1, *(I+1));
    printf("%p => %d\n", I+2, *(I+2));
    printf("%p => %d\n", I+3, *(I+3));