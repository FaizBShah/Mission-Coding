import React from "react";
import { View, Text, StyleSheet, TouchableOpacity } from  "react-native";

export default function Item(props){
    return(
        <View style={styles.item} >
            <View style={styles.itemLeft} >
                <TouchableOpacity style={styles.square} />
                <Text style={styles.itemText} >{props.text}</Text>
            </View>
            <View style={styles.circle  } ></View>
        </View>
    );
}
const styles= StyleSheet.create({
    item:{
        backgroundColor: "#FFFFFF",
        padding: 15,
        borderRadius: 10,
        flexDirection: "row",
        alignItems:"center",
        justifyContent: "space-between",
        marginBottom: 20
    }, 
    itemLeft:{
        flexDirection:"row",
        alignItems: "center",
        flexWrap: "wrap"
    },
    square:{
        backgroundColor:"#55BCF666",
        // opacity: 0.4,
        width: 24,
        height: 24,
        borderRadius: 5,
        marginRight: 15
    },
    itemText:{
        maxWidth: "80%"
    },
    circle:{
        width: 12,
        height: 12,
        borderRadius: 5,
        borderColor: "#55BCF6",
        borderWidth: 2
    }

});