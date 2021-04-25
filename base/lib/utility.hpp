#pragma once

namespace lib{
  std::string readline(std::istream& src = std::cin){
    std::string line;
    std::getline(src, line);
    return line;
  }

  template<class T>
  T read(std::istream& src = std::cin){
    T buf;
    src >> buf;
    return buf;
  }

  template<size_t INDEX, class T>
  T& read_elem(T& buf, std::istream&){
    return buf;
  }

  template<size_t INDEX, class T, class F, class... After>
  T& read_elem(T& buf, std::istream& src = std::cin){
    std::get<INDEX>(buf) = read<F>(src);
    return read_elem<INDEX + 1, T, After...>(buf, src);
  }

  template<class... T>
  std::tuple<T...> read_elems(std::istream& src = std::cin){
    std::tuple<T...> buf;

    return read_elem<0, typeof(buf), T...>(buf, src);
  }

}