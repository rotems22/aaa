int set_max_zombies(int max_z, pit_t pid){
	if (pid<o){
		errno=EINVAL;
		return -1;
	}
	if (max_z<o){
		errno=ESRCH;
		return -1;
	}
	task_struct curr;
	curr=find_task_by_pid(pid);
	curr->max_zombies = max_z;
	curr->innitalized=true;
	return 0;
}


int get_max_zombies(){
	task_struct curr;
	curr=find_task_by_pid(getpid());
	if (curr->innitalized!=true){
		errno=EINVAL;
		return -1;
	}
	return curr->max_zombies;
}
