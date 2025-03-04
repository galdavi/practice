const pokemon_container = document.getElementById('poke-container');
const pokemon_count = 152;

const colors = {
    fire: '#FDDFDF',
    grass: '#DEFDEO',
    electric: '#FCF7DE',
    water: '#DEF3FD',
    ground: '#f4e7da',
    rock: '#d5d5d4',
    fairy: '#fceaff',
    poison: '#98d7a5',
    bug: '#f8d5a3',
    dragon: '#97b3e6',
    psychic: '#eaeda1',
    flying: '#F5F5F5',
    fighting: '#E6E0D4',
    normal: '#F5F5F5',
};


const main_types = Object.keys(colors);

async function fetchPokemons() {
    for (let i = 1; i < pokemon_count; ++i) {
        await getPokemon(i);
    }
}

async function getPokemon(id) {
    const url = 'https://pokeapi.co/api/v2/pokemon/' + id;
    const response = await fetch(url);
    const data = await response.json();
    createPokemonCard(data);
}

function createPokemonCard(pokemon) {
    const pokemonElement = document.createElement('div');
    pokemonElement.classList.add('pokemon');
    const pokemonInnerHTML = `<div class="pokemon" style="background-color: rgb(222,253,224);">
            <div class="img-container">
                <img src="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/1.png" alt="">
            </div>
            <div class="info">
                <span class="number">#001</span>
                <h3 class="name">Bulbasaur</h3>
                <small class="type">Type: <span>grass</span></small>
            </div>
        </div>`;

    pokemonElement.innerHTML = pokemonInnerHTML;
    poke_container.appendChild(pokemonElement);
}