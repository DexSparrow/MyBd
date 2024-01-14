
#define help "Voici les differentes commandes :\n-createbd\n-usebd\n-removebd"

int length(char*s){int i = 0;for (i;*s; ++i){s++;}return i;}
int lengthtab(char**ss){int i = 0;for (i;*ss; ++i){ss++;}return i;}

int isExist(char*nameFile){
	FILE*t = fopen(nameFile,"r");
	if (t){
		fclose(t);
		return 1;
	}
	else {
		return 0;
	}
}

char* adjust(char*s){
	char*res = (char*)malloc((length(s) + 1)*sizeof(char));
	for (int i = 0; i < length(s); ++i){
		*(res + i) = *(s + i);
	}
	return res;
}

char* Entry(char*s){
	printf("%s",s);
	char*res = (char*)malloc(20*sizeof(char));
	scanf("%s",res);
	res = adjust(res);
	return res;
}

char lowey(char c){
	int a = (int)c;
	if (a < 97){
		return (char) (c + 32);
	}
	else {
		return c;
	}
}

int isEqual(char*a,char*b){// Par rapport a b 
	int res = 1;
	for (int i = 0; i < length(b); ++i){
		if(lowey(*(a + i)) != lowey(*(b +i))){
			res = 0;
			break;
		}
	}
	return res;
}

char* fuses(char*s,char a){
	int ls = length(s);
	int i;
	char*res = (char*)malloc((ls + 2)*sizeof(char));
	for (i = 0; i < ls; ++i){
		*(res + i)  = *(s + i);
	}
	*(res + i) = a;
	return res;
}

char* fusess(char*s,char*a){
	int ls = length(s);
	int la = length(a);
	int i;
	char*res = (char*)malloc((ls + la + 1)*sizeof(char));
	for (i = 0; i < ls; ++i){
		*(res + i)  = *(s + i);
	}
	for (int f = 0; f < la; ++f,++i){
		*(res + i)  = *(a + f);
	}
	return res;
}

char** fuseSS(char**ss,char*t){
	int lss = lengthtab(ss);
	char**res = (char**)malloc((lss + 2)*sizeof(char*));
	int i = 0;
	for (i; i < lss; ++i){
		char*tempo = (char*)malloc((length(*(ss + i)) + 1) *sizeof(char));
		for (int j = 0; j < length(*(ss + i)); ++j){
			*(tempo + j) = *((*(ss + i)) + j); 
		}
		*(res + i) = tempo;
	}
	char*tempo = (char*)malloc((length(t) + 1)*sizeof(char));

	for (int j = 0; j < length(t); ++j){
		*(tempo + j) = *(t + j);
	}
	*(res + i) = tempo;
	return res;
}

char* readliney(FILE*f){
	char a = fgetc(f);
	char* res = "";
	while(a != EOF){
		if (a == '\n'){
			res = fuses(res,' ');
			break;
		}
		res = fuses(res,a);
		a = fgetc(f);
	}
	if (length(res) == 0){
		return 0;
	}
	return res;
}

char* extractBefore(char*s,char b){// Il faut controler l'errzur avant de lancer cette fonction
	char*res = "";
	while(*s){
		if(*s == b){
			break;
		}
		if (*s != ' '){
			res = fuses(res,*s);			
		}
		s++;
	}
	return res;
}

char** extractDataName(FILE*f){
	char*a = readliney(f);
	char**res = (char**)malloc(0*sizeof(char*));
	while(a){
		if (*a != ' '){
			res = fuseSS(res,extractBefore(a,':'));
		}
		a = readliney(f);
	}
	return res;
}

char* extractAfter(char*s,char b){// Il faut controler l'errzur avant de lancer cette fonction
	char*res = "";
	int r = 0;
	while(*s){
		if(r){
			if(*s != ' '){
				res = fuses(res,*s);							
			}
		}

		if(*s == b){
			r = 1;
		}
		s++;
	}
	return res;
}

char** extractDataType(FILE*f){
	char*a = readliney(f);
	char**res = (char**)malloc(0*sizeof(char*));
	while(a){
		if (*a != ' '){
			res = fuseSS(res,extractAfter(a,':'));
		}
		a = readliney(f);
	}
	return res;
}

