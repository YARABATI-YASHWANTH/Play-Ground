// Smooth Scrolling
document.querySelectorAll('a[href^="#"]').forEach(anchor => {
    anchor.addEventListener('click', function (e) {
        e.preventDefault();

        document.querySelector(this.getAttribute('href')).scrollIntoView({
            behavior: 'smooth'
        });
    });
});

// Card Hover Animation
const cards = document.querySelectorAll('.card');

cards.forEach(card => {
    card.addEventListener('mouseover', () => {
        card.style.transform = 'scale(1.05)';
        card.style.transition = 'transform 0.3s';
    });

    card.addEventListener('mouseout', () => {
        card.style.transform = 'scale(1)';
        card.style.transition = 'transform 0.3s';
    });
});

// Jumbotron Text Animation
const jumbotronText = document.querySelector('.jumbotron h1');
let typingEffect = new Typed('.jumbotron h1', {
    strings: ['Code with Yash', 'Learn Computer Science'],
    typeSpeed: 100,
    backSpeed: 50,
    loop: true
});

// Scroll Reveal Animation
window.addEventListener('scroll', () => {
    let reveals = document.querySelectorAll('.reveal');

    for (let i = 0; i < reveals.length; i++) {
        let windowHeight = window.innerHeight;
        let revealTop = reveals[i].getBoundingClientRect().top;
        let revealPoint = 150;

        if (revealTop < windowHeight - revealPoint) {
            reveals[i].classList.add('active');
        } else {
            reveals[i].classList.remove('active');
        }
    }
});

const form = document.getElementById('registerForm');

form.addEventListener('submit', (e) => {
  e.preventDefault();

  const username = document.getElementById('username').value.trim();
  const email = document.getElementById('email').value.trim();
  const password = document.getElementById('password').value.trim();
  const confirmPassword = document.getElementById('confirmPassword').value.trim();

  if (password !== confirmPassword) {
    alert('Passwords do not match');
    return;
  }

  // Store registration details in local storage
  const registrationDetails = {
    username,
    email,
    password
  };

  localStorage.setItem('registrationDetails', JSON.stringify(registrationDetails));

  // Reset form
  form.reset();

  alert('Registration successful!');
});

const lform = document.getElementById('loginForm');

lform.addEventListener('submit', (e) => {
  e.preventDefault();

  const email = document.getElementById('email').value.trim();
  const password = document.getElementById('password').value.trim();

  const registrationDetails = JSON.parse(localStorage.getItem('registrationDetails'));

  if (registrationDetails && registrationDetails.email === email && registrationDetails.password === password) {
    alert('Login successful!');
    // Redirect to the desired page or perform any other actions
  } else {
    alert('Invalid email or password');
  }
});

// function getRandomInt(min, max) {
//     return Math.floor(Math.random() * (max - min + 1)) + min;
//   }

//   function getRandomDirection() {
//     const directions = ['N', 'NE', 'E', 'SE', 'S', 'SW', 'W', 'NW'];
//     return directions[Math.floor(Math.random() * directions.length)];
//   }
//   setInterval(function() {
//     document.getElementById('temperature').innerHTML = getRandomInt(-10, 40);
//     document.getElementById('windSpeed').innerHTML = getRandomInt(0, 100);
//     document.getElementById('direction').innerHTML = getRandomDirection();
//   }, 6000); // 60000 milliseconds = 1 minute
  