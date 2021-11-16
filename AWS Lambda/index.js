exports.handler = async (event) => {
    console.log('Function started running :)');

    const accountSid = process.env.ACCOUNT_SID;
    const authToken = process.env.AUTH_TOKEN;
    const twilioPhoneNumber = process.env.TWILIO_PHONE;
    const targetPhoneNumber = event.target;
    const message = event.message;

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
            return response;
        } 
        catch (error) 
        { 
            console.error(error);
            return null;
        }
    }

    // MAIN
    const result = await sendSms(message);

    const response = {
        statusCode: result == null? 400 : 200,
        body: result || {},
    };
    console.log('Function has reached return statement :)');
    return response;
};