/**add_to_entry.s**/
.long SYMBOL_NAME(sys_set_max_zombies)
	.long SYMBOL_NAME(sys_get_max_zombies)
	.long SYMBOL_NAME(sys_get_zombies_count)
	.long SYMBOL_NAME(sys_get_zombie_pid)
	.long SYMBOL_NAME(sys_give_up_zombies)
