int set_max_zombies(int max_z, pid_t pid){
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



int give_up_zombies(int n, pid_t adopter_pid){
	if (n > get_zombies_count(){
		errno=EINVAL;
		return -1;
	}
	int new_count = n;
	new_count += get_zombies_count(adopter_pid);
	if (new_count>get_max_zombies(adopter_pid)){
		errno=EINVAL;
		return -1;
	}
	if (get_max_zombies() == -1){
		errno=EINVAL;
		return -1;
	}
	if (adopter_pid < 0){
		errno=ESRCH;
		return 0;
	}

	pid_t curr_pid;
	task_struct curr_task;
	task_struct adopter_task;
	for(int i=0; i!=n; i++){
		curr_pid=get_zombies_pid(i);
		curr_task=find_task_by_pid(curr_pid);
		adopter_task=find_task_by_pid();
		adopter_task->counter++;
		curr_task->counter--;

		**fix lists**

	}




}