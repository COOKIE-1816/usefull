bool find(const char* __source, const char* __occurence) {
	size_t i0, i1;
	
	size_t lenSource 	= sizeof(__source) 		/ sizeof(__source[0]);
	size_t lenOccurence	= sizeof(__occurence) 	/ sizeof(__occurence[0]);
	
	static char* _buffer = "";
	
	bool c;
	
	if(lenSource < lenOccurence) 
		return false;
	
	if(__source == __occurence)
		return true;
	
	for(i0 = 0; i0 < lenSource; i0++) {
		
	}
	
	return false;
}