/* ハッシュ関数 */
int	hash_func(char *name)
{
 int total=0;
 while(*name!='\0'){
	 total+=*name;
	 name++;
 }
 return(total%11);

}