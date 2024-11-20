import streamlit as st
import pandas as pd


def main():
    uploaded_file = st.file_uploader("Загрузите файл с данными", type=["txt", "csv"])

    if uploaded_file is not None:
        try:
            df = pd.read_csv(uploaded_file, header=None)
            x_values = df.iloc[0].dropna().values
            fx_values = df.iloc[1].dropna().values

            if len(x_values) != len(fx_values):
                st.error("Ошибка: массивы x и f(x) должны быть одинаковой длины.")
                return

            data = pd.DataFrame({
                'x': x_values,
                'f(x)': fx_values
            }).set_index('x')

            st.line_chart(data, x_label='Длина стороны квадрата', y_label='Ошибка')

        except Exception as e:
            st.error(f"Ошибка при обработке файла: {e}")


if __name__ == "__main__":
    main()
