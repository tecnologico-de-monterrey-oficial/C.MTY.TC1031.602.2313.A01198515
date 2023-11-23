


HashTable::HashTable(){
    table.resize(100);
}

int HastTable::hash(string data){
    return
}

bool HashTable::insert(string data){
    int index=hash(data);
    table[index]=data;
}

int HashTable::findData(string data){
    int index= hash(data);
    if( table[index]==data){
        return index;
    } else {
        return-1;
    }

}