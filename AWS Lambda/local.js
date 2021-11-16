// ENV VARIABLES
require('dotenv').config();
const accountSid = process.env.ACCOUNT_SID;
const authToken = process.env.AUTH_TOKEN;
const twilioPhoneNumber = process.env.TWILIO_PHONE;
const targetPhoneNumber = process.env.TARGET_PHONE;

// TWILIO
const client = require('twilio')(accountSid, authToken);

async function sendSms(message) 
{
    try 
    {
        const response = await client.messages.create({
            to: targetPhoneNumber,
            from: twilioPhoneNumber,
            body: message
        });
        console.log(response);
        console.log(response.sid)
    } 
    catch (error) 
    { 
        console.error(error) ;
    }
}

// MAIN
sendSms('Well, hello there!');