struct LinearList
{
int coeff;
LinearList *next;
};
void AddListElem(int NewListElem, LinearList *&First)
{
LinearList *NewElem = new LinearList;
NewElem->next = NULL;
NewElem->coeff = NewListElem;
if (First == NULL)
First = NewElem;
else
{
LinearList *tmp = First;
while (tmp->next != NULL)
{
tmp = tmp->next;
}
tmp->next = NewElem;
}
}
void GetSequence(LinearList *Perv, LinearList *&FinalSequence)
{
LinearList *ResultCarriage = new LinearList;
LinearList *Carriage = new LinearList;
Carriage = Perv;
//Участок с обходом четных элементов
if (Carriage->next != NULL)
{
Carriage = Carriage->next;
FinalSequence = new LinearList;
FinalSequence->coeff = Carriage->coeff;
ResultCarriage = FinalSequence;
while (Carriage->next != NULL)
{
if (Carriage->next->next != NULL)
{
Carriage = Carriage->next->next;
ResultCarriage->next = new LinearList;
ResultCarriage->next->coeff = Carriage->coeff;
ResultCarriage = ResultCarriage->next;
}
else break;
}
}
else
{
FinalSequence = new LinearList;
FinalSequence->coeff = Carriage->coeff;
return;
}
//Участок с обходом нечетных элементов
Carriage = Perv;
ResultCarriage->next = new LinearList;
ResultCarriage->next->coeff=Carriage->coeff;
ResultCarriage = ResultCarriage->next;
while (Carriage->next != NULL)
{
if (Carriage->next->next != NULL)
{
Carriage = Carriage->next->next;
ResultCarriage->next = new LinearList;
ResultCarriage->next->coeff = Carriage->coeff;
ResultCarriage = ResultCarriage->next;
}
else break;
}
ResultCarriage->next = NULL;
}