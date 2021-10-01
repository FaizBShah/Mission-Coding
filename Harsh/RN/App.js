import React, {useState} from 'react';
import { Keyboard, KeyboardAvoidingView, Platform, StyleSheet, Text, TextInput, TouchableOpacity, View, ScrollView } from 'react-native';

import Item from './components/Item';

export default function App() {

  const [task, setTask]=useState("");
  const [taskArr, setTaskArr]=useState([]);

  function handleChange(text){
    setTask(text);
  }
  function handleClick(){
    Keyboard.dismiss();
    setTaskArr([...taskArr, task]);
    setTask("");
  }
  function handleRemove(index){
    let itemsCopy=[...taskArr];
    itemsCopy.splice(index,1);
    setTaskArr(itemsCopy);
  }
  return (
    <View style={styles.container}>

      <View style={styles.main} >

        {/* Title */}
        <Text style={styles.title} >Today's Task</Text>

        {/* This will contain the items */}
        <ScrollView style={styles.items}   showsVerticalScrollIndicator ={false} showsHorizontalScrollIndicator={false} >
          {taskArr.map((items, index)=>{
            return(
              <TouchableOpacity key={index} onPress={()=> handleRemove(index)} >
                <Item text={items} />
              </TouchableOpacity>
            )
          })}
        </ScrollView>
      </View>

      <KeyboardAvoidingView behavior={Platform.OS==="ios" ? "padding" : 'height' }style={styles.textInputBox}>
        
        <TextInput style={styles.input} placeholder="Create task" value={task} onChangeText={handleChange} />
          
        <TouchableOpacity onPress={handleClick} >
          <View style={styles.addBox} >
            <Text>+</Text>
          </View>
        </TouchableOpacity>
      
      </KeyboardAvoidingView>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#E8EAED',
  },
  main:{
    paddingTop: 80,
    paddingHorizontal: 20,
  }, 
  title:{
    fontSize: 24,
    fontWeight:'bold'
  },
  items:{
    marginTop: 30
  },
  textInputBox:{
    position:'absolute',
    bottom: 0,
    width: "100%",
    flexDirection:'row',
    justifyContent:'space-around',
    alignItems:'center',
    backgroundColor: "#E8EAED"
  }, 
  input: {
    paddingVertical: 10,
    paddingHorizontal: 10,
    width: "80%",
    backgroundColor: "#ffffff",
    borderRadius: 60,
    borderColor: "#C0C0C0",
    borderWidth: 1
  },
  addBox:{
    width: 50,
    height: 50,
    backgroundColor: "#ffffff",
    borderRadius: 60,
    justifyContent:'center',
    alignItems:'center',
    borderColor: "#C0C0C0",
    borderWidth: 1
  }
});
