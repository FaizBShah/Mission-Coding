import React from 'react'
import './ThirdComp.css';
import image from './newApp.png';
import appstore from './app_store.png';
import playstore from './play_store.png';
export default function ThirdComp() {
    return (
        <>
        <div className="ThirdComp">
        <div className="newappHead">
            <p className="ThirdHead">Get the learning app for free</p>
            <p>Download lessons and learn anytime, anywhere with the Unacademy app</p>
        <img alt="hi" src={playstore} data-aos="fade-up"  className="store" />
        <img alt="hi" src={appstore} data-aos="fade-down"  className="store" />
            </div>
            <img alt="hi" src={image} data-aos="fade-up" className="newApp"/>
        </div>
        </>
    )
}
