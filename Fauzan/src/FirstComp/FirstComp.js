import React from 'react'
import banner from './banner1.PNG';
import './FirstComp.css';
export default function FirstComp() {
    return (
        <>
        <div className="FirstComp" data-aos="fade-left">
            <img alt="hi" src={banner} className="banner" />
        </div>
        <div data-aos="fade-right" className="FirstText">
            <p className="FirstTextText">India’s largest<br/>learning platform
            </p>
        </div>
        </>
    )
}
