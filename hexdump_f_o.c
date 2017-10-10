static void hexdump (const void* data, size_t size){
  const unsigned char * p, * q;
  int i;
  p = data;
  
  while (size)
  {
    q = p;
    printf("%p: ", (void *) p);
    
    for (i = 0; i < colnum && size; ++i)
    {
      printf("%02X ", *p);
      ++p;
      --size;
    }
    size += i;
    while (i < colnum)
    {
      printf("XX ");
      ++i;
    }
  printf("| ");
  
  p=q;
  
  for (i = 0; i < colnum && size; ++i)
  {
    printf("%c", isprint(*p) && !isspace(*p) ? *p : ' ');
    ++p;
    --size;
  }
  while (i < colnum)
  {
    printf("");
    ++i;
  }
  printf(" |\n");
  
}    
return;
}