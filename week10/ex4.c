#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
long unsigned i_node_numbers[20][3];

struct name_inode
{
	char name[20];
	long unsigned node_numb;
};
void in_array(long unsigned  numb){
	int i;
	int found=0;
	for(i=0;i<20;i++){
		if(numb==i_node_numbers[i][0]){
			++i_node_numbers[i][1];
			found=1;
			break;
		}
	}
	if (found==0){
		for (int i = 0; i < 20; ++i)
		{
			if (i_node_numbers[i][0]==-1){
				i_node_numbers[i][0]=numb;
				++i_node_numbers[i][1];
				break;
			}
		}
	}

}

int main(){
	DIR *dirp = opendir("tmp");
	FILE *f =fopen("ex4.txt","w");
	struct dirent *entity;
	struct stat ent_stat;
	int i;
	struct name_inode inode_array[40];
	char filepath[300];
	char filenames[20][40];
	int num_of_files=0;
	for (int i = 0; i < 20; ++i)
	{
		i_node_numbers[i][0]=-1;
		i_node_numbers[i][1]=0;
		i_node_numbers[i][2]=0;
	}
	while((entity=readdir(dirp))!=NULL){
		sprintf(filepath, "tmp/%s",entity->d_name);
		stat(filepath, &ent_stat);
		sprintf(inode_array[num_of_files].name,"%s",entity->d_name);
		inode_array[num_of_files].node_numb=ent_stat.st_ino;
		++num_of_files;
		if(&ent_stat!=NULL){
			in_array(ent_stat.st_ino);
			//printf("%ld\n",ent_stat.st_ino);
		}
	}
	int j;
	for (int i = 0; i < 20; ++i)
	{
		if(i_node_numbers[i][1]>1){
			for (int j = 0; j < num_of_files; ++j)
			{
				if(inode_array[j].node_numb==i_node_numbers[i][0])
					fprintf(f, "%s ",inode_array[j].name);
			}
			fprintf(f, "\n");
		}
	}
	return 0;
}