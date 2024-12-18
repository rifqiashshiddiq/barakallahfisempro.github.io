<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Launching Hadiah</title>
  <style>
    body {
      margin: 0;
      padding: 0;
      font-family: 'Arial', sans-serif;
      display: flex;
      justify-content: center;
      align-items: center;
      height: 100vh;
      color: #ffffff;
      text-align: center;
      overflow: hidden;
    }

    /* Background photo */
    body::before {
      content: "";
      position: absolute;
      top: 0;
      left: 0;
      width: 100%;
      height: 100%;
      background: url('https://img.freepik.com/premium-photo/woman-running-autumn-field-sunset-healthy-lifestyle-concept-active-sportive-people_106029-12.jpg?w=826') 
        no-repeat center center/cover;
      filter: brightness(50%);
      z-index: -1;
    }

    h1 {
      font-size: 2.8rem;
      margin: 0 20px;
      text-transform: uppercase;
      letter-spacing: 3px;
    }

    #countdown {
      font-size: 3.5rem;
      font-weight: bold;
      margin: 20px 0;
      letter-spacing: 2px;
    }

    #password-section {
      display: none;
      margin-top: 20px;
    }

    #password-input {
      padding: 10px;
      font-size: 1rem;
      border: none;
      border-radius: 5px;
      outline: none;
    }

    #submit-password {
      padding: 10px 20px;
      font-size: 1rem;
      margin-left: 10px;
      background: #ff4500;
      color: #fff;
      border: none;
      border-radius: 5px;
      cursor: pointer;
      transition: 0.3s;
    }

    #submit-password:hover {
      background: #fff;
      color: #ff4500;
    }

    a {
      display: none;
      text-decoration: none;
      background: #ff4500;
      color: #fff;
      font-size: 1.5rem;
      padding: 15px 30px;
      border-radius: 50px;
      transition: 0.3s;
      box-shadow: 0 4px 10px rgba(0, 0, 0, 0.4);
    }

    a:hover {
      background: #fff;
      color: #ff4500;
    }

    /* Responsiveness */
    @media (max-width: 768px) {
      h1 {
        font-size: 2rem;
      }
      #countdown {
        font-size: 2rem;
      }
      a {
        font-size: 1.2rem;
        padding: 10px 20px;
      }
    }

    @media (max-width: 480px) {
      h1 {
        font-size: 1.8rem;
      }
      #countdown {
        font-size: 1.5rem;
      }
      a {
        font-size: 1rem;
        padding: 8px 16px;
      }
    }
  </style>
</head>
<body>
  <div>
    <h1>Countdown to Launch</h1>
    <div id="countdown"></div>
    <div id="password-section">
      <input type="password" id="password-input" placeholder="Enter password">
      <button id="submit-password">Submit</button>
    </div>
    <a id="launch-link" href="https://docs.google.com/document/d/1xVjty2MbxfobYtdNnNnOlYw-oI4QQiledWqdNLVuc1I/edit?usp=sharing">Claim Your Prize!</a>
  </div>

  <script>
    const countdownElement = document.getElementById('countdown');
    const passwordSection = document.getElementById('password-section');
    const passwordInput = document.getElementById('password-input');
    const submitPassword = document.getElementById('submit-password');
    const linkElement = document.getElementById('launch-link');
    const targetDate = new Date('December 19, 2024 18:38:30').getTime();
    const correctPassword = "besok pergi makan?";

    function updateCountdown() {
      const now = new Date().getTime();
      const distance = targetDate - now;

      if (distance <= 0) {
        countdownElement.innerText = "Hadiahnya Masih diperjalanan 🚚!";
        passwordSection.style.display = "block";
        clearInterval(interval);
        return;
      }

      const days = Math.floor(distance / (1000 * 60 * 60 * 24));
      const hours = Math.floor((distance % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
      const minutes = Math.floor((distance % (1000 * 60 * 60)) / (1000 * 60));
      const seconds = Math.floor((distance % (1000 * 60)) / 1000);

      countdownElement.innerText = `${days}d ${hours}h ${minutes}m ${seconds}s`;
    }

    const interval = setInterval(updateCountdown, 1000);
    updateCountdown();

    // Handle password verification
    submitPassword.addEventListener('click', () => {
      if (passwordInput.value === correctPassword) {
        passwordSection.style.display = "none";
        linkElement.style.display = "inline-block";
      } else {
        alert("Password salah! Silakan coba lagi.");
      }
    });
  </script>
</body>
</html>
