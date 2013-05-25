/*　構造体 score_node　を定義してください　*/
struct score_node
{
	unsigned int no;
	char name[20];
	unsigned int score;
	struct score_node *next;
};
