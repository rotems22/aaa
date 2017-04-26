int​ set_max_zombies_system_call ​(​int max_z, pid_t pid)​
 ​{
   ​unsigned​ ​int​ res​;
	__asm__​( 
    	"int $0x80;"
        	:​ ​"=a"​ ​(​res​)
            :​ ​"0"​ ​(​244)​ ​,​"b"​ ​(max_z)​ ​,​"c"​ ​(pid)
            :​ ​"memory" 
    ​); 
    if​ ​(​res ​>=​ ​(​unsigned​ ​long​)(-​125​))
    {      
    	errno ​=​ ​-​res​;
    	res ​=​ ​-​1​;
    } 
        return​ ​(​int​)​ res​;  
    } 


    int​ get_max_zombies_system_call ​(​)​
 ​{
   ​unsigned​ ​int​ res​;
	__asm__​( 
    	"int $0x80;"
        	:​ ​"=a"​ ​(​res​)
            :​ ​"0"​ ​(​245)​ ​,​
            :​ ​"memory" 
    ​); 
    if​ ​(​res ​>=​ ​(​unsigned​ ​long​)(-​125​))
    {      
    	errno ​=​ ​-​res​;
    	res ​=​ ​-​1​;
    } 
        return​ ​(​int​)​ res​;  
    } 

    int​ get_zombies_count_system_call ​(​pid_t pid)​
 ​{
   ​unsigned​ ​int​ res​;
	__asm__​( 
    	"int $0x80;"
        	:​ ​"=a"​ ​(​res​)
            :​ ​"0"​ ​(​246)​ ​,​"b"​ ​(pid)
            :​ ​"memory" 
    ​); 
    if​ ​(​res ​>=​ ​(​unsigned​ ​long​)(-​125​))
    {      
    	errno ​=​ ​-​res​;
    	res ​=​ ​-​1​;
    } 
        return​ ​(​int​)​ res​;  
    } 

    int​ get_zombie_pid_system_call ​(​int n
   ​pid_t res​;
	__asm__​( 
    	"int $0x80;"
        	:​ ​"=a"​ ​(​res​)
            :​ ​"0"​ ​(​247)​ ​,​"b"​ ​(n)​ ​
            :​ ​"memory" 
    ​); 
    if​ ​(​res ​>=​ ​(​unsigned​ ​long​)(-​125​))
    {      
    	errno ​=​ ​-​res​;
    	res ​=​ ​-​1​;
    } 
        return​ res​;  
    } 

    int​ give_up_zombies_system_call ​(​int n, pid_t adopter_pid)​
 ​{
   ​unsigned​ ​int​ res​;
	__asm__​( 
    	"int $0x80;"
        	:​ ​"=a"​ ​(​res​)
            :​ ​"0"​ ​(​248)​ ​,​"b"​ ​(n)​ ​,​"c"​ ​(adopter_pid)
            :​ ​"memory" 
    ​); 
    if​ ​(​res ​>=​ ​(​unsigned​ ​long​)(-​125​))
    {      
    	errno ​=​ ​-​res​;
    	res ​=​ ​-​1​;
    } 
        return​ ​(​int​)​ res​;  
    } 