int sys_set_max_zombies(int max_z, pid_t pid){
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


int sys_get_max_zombies(){
	task_struct curr;
	curr=find_task_by_pid(getpid());
	if (curr->innitalized!=true){
		errno=EINVAL;
		return -1;
	}
	return curr->max_zombies;
}

int sys_get_zombies_count(pid_t pid){
	if (pid < 0){
		errno=ESRCH;
		return -1;
	}
	return zombies_counter;
}

pid_t sys_get_zombie_pid(int n){
	if (n < 0){
		errno=EINVAL;
		return -1;
	}

	if (zombies_counter <= n){
		errno=EINVAL;
		return -1;
	}
	task_struct *curr_task;
	curr_task=find_task_by_pid(getpid());
	 if (curr->innitialized==false){
		errno=EINVAL;
		return -1;
	}

	list_t *curr_list;
	curr_list=curr_task->zombies_list:
	int Ncount=0;
	list_for_each(CurNode,curr_list){
		if(n==Ncount){
			return list_entry(CurNode,task_struct,zombies_list);
		}
		Ncount++;
	}
		return list_entry(CurNode,task_struct,zombies_list);
	}




int sys_give_up_zombies(int n, pid_t adopter_pid){
	pid_t curr_pid;
	list_t *pid_node;
	task_struct *curr_task;
	task_struct *adopter_task;
	adopter_task=find_task_by_pid(adopter_pid);

	if (n < 0){
		errno=EINVAL;
		return -1;
	}

	if (n > get_zombies_count()){
		errno=EINVAL;
		return -1;
	}
	int new_count = n;
	new_count += get_zombies_count(adopter_pid);
	if(adopter_pid!=getpid()){
		if (new_count>get_max_zombies(adopter_pid)){
			errno=EINVAL;
			return -1;
		}
	}
	

	if (adopter_task->innitialized==false){
		errno=EINVAL;
		return -1;
	}
	if (adopter_pid < 0){
		errno=ESRCH;
		return -1;
	}

	for(int i=0; i!=n; i++){
		curr_pid=get_zombies_pid(i);
		curr_task=find_task_by_pid(curr_pid);
		
		REMOVE_LINKS(curr_pid);
		curr_task->p_pptr=adopter_task;
		SET_LINKS(curr_pid);

		pid_node=find_pid_node(curr_pid);
		list_add(pid_node,adopter_task->zombies_list);
		list_del(pid_node);
	
		adopter_task->zombies_counter++;
		curr_task->zombies_counter--;
	}
	return 0;
}

list_t* find_pid_node(pid_t pid){
	task_struct *curr_task;
	curr_task=find_task_by_pid(pid);
	list_t *curr_list;
	curr_list = &(curr_task->zombies_list):

	list_for_each(CurNode,curr_list){
			if(pid==list_entry(CurNode,task_struct,zombies_list));
			return CurNode;
	}
	return curr_list;
}






