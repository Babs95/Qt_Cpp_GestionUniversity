PGDMP         3                w            Qt    11.2    11.2 F    V           0    0    ENCODING    ENCODING        SET client_encoding = 'UTF8';
                       false            W           0    0 
   STDSTRINGS 
   STDSTRINGS     (   SET standard_conforming_strings = 'on';
                       false            X           0    0 
   SEARCHPATH 
   SEARCHPATH     8   SELECT pg_catalog.set_config('search_path', '', false);
                       false            Y           1262    49736    Qt    DATABASE     �   CREATE DATABASE "Qt" WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'French_France.1252' LC_CTYPE = 'French_France.1252';
    DROP DATABASE "Qt";
             postgres    false            �            1259    49737    non_boursier    TABLE     �   CREATE TABLE public.non_boursier (
    id integer NOT NULL,
    adresse character varying(100) NOT NULL,
    idet integer NOT NULL
);
     DROP TABLE public.non_boursier;
       public         postgres    true            �            1259    49740    adresse_id_seq    SEQUENCE     �   CREATE SEQUENCE public.adresse_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 %   DROP SEQUENCE public.adresse_id_seq;
       public       postgres    false    196            Z           0    0    adresse_id_seq    SEQUENCE OWNED BY     F   ALTER SEQUENCE public.adresse_id_seq OWNED BY public.non_boursier.id;
            public       postgres    false    197            �            1259    49742    batiment    TABLE     ^   CREATE TABLE public.batiment (
    id integer NOT NULL,
    libelle character varying(100)
);
    DROP TABLE public.batiment;
       public         postgres    true            �            1259    49745    batiment_id_seq    SEQUENCE     �   CREATE SEQUENCE public.batiment_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 &   DROP SEQUENCE public.batiment_id_seq;
       public       postgres    false    198            [           0    0    batiment_id_seq    SEQUENCE OWNED BY     C   ALTER SEQUENCE public.batiment_id_seq OWNED BY public.batiment.id;
            public       postgres    false    199            �            1259    49747    bourses    TABLE     �   CREATE TABLE public.bourses (
    id integer NOT NULL,
    montant character varying(100) NOT NULL,
    idtype integer NOT NULL
);
    DROP TABLE public.bourses;
       public         postgres    true            �            1259    49750    bourses_id_seq    SEQUENCE     �   CREATE SEQUENCE public.bourses_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 %   DROP SEQUENCE public.bourses_id_seq;
       public       postgres    false    200            \           0    0    bourses_id_seq    SEQUENCE OWNED BY     A   ALTER SEQUENCE public.bourses_id_seq OWNED BY public.bourses.id;
            public       postgres    false    201            �            1259    49752    boursier    TABLE     k   CREATE TABLE public.boursier (
    id integer NOT NULL,
    idet integer NOT NULL,
    idbourse integer
);
    DROP TABLE public.boursier;
       public         postgres    true            �            1259    49755    boursier_id_seq    SEQUENCE     �   CREATE SEQUENCE public.boursier_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 &   DROP SEQUENCE public.boursier_id_seq;
       public       postgres    false    202            ]           0    0    boursier_id_seq    SEQUENCE OWNED BY     C   ALTER SEQUENCE public.boursier_id_seq OWNED BY public.boursier.id;
            public       postgres    false    203            �            1259    49757    chambre    TABLE     y   CREATE TABLE public.chambre (
    id integer NOT NULL,
    libelle character varying(100),
    idbat integer NOT NULL
);
    DROP TABLE public.chambre;
       public         postgres    true            �            1259    49760    chambre_id_seq    SEQUENCE     �   CREATE SEQUENCE public.chambre_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 %   DROP SEQUENCE public.chambre_id_seq;
       public       postgres    false    204            ^           0    0    chambre_id_seq    SEQUENCE OWNED BY     A   ALTER SEQUENCE public.chambre_id_seq OWNED BY public.chambre.id;
            public       postgres    false    205            �            1259    49762    etudiant    TABLE     A  CREATE TABLE public.etudiant (
    id integer NOT NULL,
    matricule character varying(200) NOT NULL,
    nom character varying(200) NOT NULL,
    prenom character varying(200) NOT NULL,
    datenaiss character varying(100) NOT NULL,
    email character varying(100) NOT NULL,
    tel character varying(100) NOT NULL
);
    DROP TABLE public.etudiant;
       public         postgres    true            �            1259    49768    etudiant_id_seq    SEQUENCE     �   CREATE SEQUENCE public.etudiant_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 &   DROP SEQUENCE public.etudiant_id_seq;
       public       postgres    false    206            _           0    0    etudiant_id_seq    SEQUENCE OWNED BY     C   ALTER SEQUENCE public.etudiant_id_seq OWNED BY public.etudiant.id;
            public       postgres    false    207            �            1259    49770    logement    TABLE     �   CREATE TABLE public.logement (
    id integer NOT NULL,
    libelle character varying(100) NOT NULL,
    idch integer NOT NULL
);
    DROP TABLE public.logement;
       public         postgres    true            �            1259    49773    logement_id_seq    SEQUENCE     �   CREATE SEQUENCE public.logement_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 &   DROP SEQUENCE public.logement_id_seq;
       public       postgres    false    208            `           0    0    logement_id_seq    SEQUENCE OWNED BY     C   ALTER SEQUENCE public.logement_id_seq OWNED BY public.logement.id;
            public       postgres    false    209            �            1259    49775    loger    TABLE     s   CREATE TABLE public.loger (
    id integer NOT NULL,
    idet integer NOT NULL,
    idlogement integer NOT NULL
);
    DROP TABLE public.loger;
       public         postgres    true            �            1259    49778    loger_id_seq    SEQUENCE     �   CREATE SEQUENCE public.loger_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 #   DROP SEQUENCE public.loger_id_seq;
       public       postgres    false    210            a           0    0    loger_id_seq    SEQUENCE OWNED BY     =   ALTER SEQUENCE public.loger_id_seq OWNED BY public.loger.id;
            public       postgres    false    211            �            1259    49780    role    TABLE     c   CREATE TABLE public.role (
    id integer NOT NULL,
    libelle character varying(100) NOT NULL
);
    DROP TABLE public.role;
       public         postgres    true            �            1259    49783    role_id_seq    SEQUENCE     �   CREATE SEQUENCE public.role_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 "   DROP SEQUENCE public.role_id_seq;
       public       postgres    false    212            b           0    0    role_id_seq    SEQUENCE OWNED BY     ;   ALTER SEQUENCE public.role_id_seq OWNED BY public.role.id;
            public       postgres    false    213            �            1259    49785    type_bourses    TABLE     k   CREATE TABLE public.type_bourses (
    id integer NOT NULL,
    libelle character varying(100) NOT NULL
);
     DROP TABLE public.type_bourses;
       public         postgres    true            �            1259    49788    type_bourses_id_seq    SEQUENCE     �   CREATE SEQUENCE public.type_bourses_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 *   DROP SEQUENCE public.type_bourses_id_seq;
       public       postgres    false    214            c           0    0    type_bourses_id_seq    SEQUENCE OWNED BY     K   ALTER SEQUENCE public.type_bourses_id_seq OWNED BY public.type_bourses.id;
            public       postgres    false    215            �            1259    49790    user    TABLE     �   CREATE TABLE public."user" (
    id integer NOT NULL,
    login character varying(100) NOT NULL,
    password character varying(100) NOT NULL,
    idrole integer NOT NULL
);
    DROP TABLE public."user";
       public         postgres    true            �            1259    49793    user_id_seq    SEQUENCE     �   CREATE SEQUENCE public.user_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 "   DROP SEQUENCE public.user_id_seq;
       public       postgres    false    216            d           0    0    user_id_seq    SEQUENCE OWNED BY     =   ALTER SEQUENCE public.user_id_seq OWNED BY public."user".id;
            public       postgres    false    217            �
           2604    49796    batiment id    DEFAULT     j   ALTER TABLE ONLY public.batiment ALTER COLUMN id SET DEFAULT nextval('public.batiment_id_seq'::regclass);
 :   ALTER TABLE public.batiment ALTER COLUMN id DROP DEFAULT;
       public       postgres    false    199    198            �
           2604    49797 
   bourses id    DEFAULT     h   ALTER TABLE ONLY public.bourses ALTER COLUMN id SET DEFAULT nextval('public.bourses_id_seq'::regclass);
 9   ALTER TABLE public.bourses ALTER COLUMN id DROP DEFAULT;
       public       postgres    false    201    200            �
           2604    49798    boursier id    DEFAULT     j   ALTER TABLE ONLY public.boursier ALTER COLUMN id SET DEFAULT nextval('public.boursier_id_seq'::regclass);
 :   ALTER TABLE public.boursier ALTER COLUMN id DROP DEFAULT;
       public       postgres    false    203    202            �
           2604    49799 
   chambre id    DEFAULT     h   ALTER TABLE ONLY public.chambre ALTER COLUMN id SET DEFAULT nextval('public.chambre_id_seq'::regclass);
 9   ALTER TABLE public.chambre ALTER COLUMN id DROP DEFAULT;
       public       postgres    false    205    204            �
           2604    49800    etudiant id    DEFAULT     j   ALTER TABLE ONLY public.etudiant ALTER COLUMN id SET DEFAULT nextval('public.etudiant_id_seq'::regclass);
 :   ALTER TABLE public.etudiant ALTER COLUMN id DROP DEFAULT;
       public       postgres    false    207    206            �
           2604    49801    logement id    DEFAULT     j   ALTER TABLE ONLY public.logement ALTER COLUMN id SET DEFAULT nextval('public.logement_id_seq'::regclass);
 :   ALTER TABLE public.logement ALTER COLUMN id DROP DEFAULT;
       public       postgres    false    209    208            �
           2604    49802    loger id    DEFAULT     d   ALTER TABLE ONLY public.loger ALTER COLUMN id SET DEFAULT nextval('public.loger_id_seq'::regclass);
 7   ALTER TABLE public.loger ALTER COLUMN id DROP DEFAULT;
       public       postgres    false    211    210            �
           2604    49795    non_boursier id    DEFAULT     m   ALTER TABLE ONLY public.non_boursier ALTER COLUMN id SET DEFAULT nextval('public.adresse_id_seq'::regclass);
 >   ALTER TABLE public.non_boursier ALTER COLUMN id DROP DEFAULT;
       public       postgres    false    197    196            �
           2604    49803    role id    DEFAULT     b   ALTER TABLE ONLY public.role ALTER COLUMN id SET DEFAULT nextval('public.role_id_seq'::regclass);
 6   ALTER TABLE public.role ALTER COLUMN id DROP DEFAULT;
       public       postgres    false    213    212            �
           2604    49804    type_bourses id    DEFAULT     r   ALTER TABLE ONLY public.type_bourses ALTER COLUMN id SET DEFAULT nextval('public.type_bourses_id_seq'::regclass);
 >   ALTER TABLE public.type_bourses ALTER COLUMN id DROP DEFAULT;
       public       postgres    false    215    214            �
           2604    49805    user id    DEFAULT     d   ALTER TABLE ONLY public."user" ALTER COLUMN id SET DEFAULT nextval('public.user_id_seq'::regclass);
 8   ALTER TABLE public."user" ALTER COLUMN id DROP DEFAULT;
       public       postgres    false    217    216            @          0    49742    batiment 
   TABLE DATA               /   COPY public.batiment (id, libelle) FROM stdin;
    public       postgres    false    198   D       B          0    49747    bourses 
   TABLE DATA               6   COPY public.bourses (id, montant, idtype) FROM stdin;
    public       postgres    false    200   gD       D          0    49752    boursier 
   TABLE DATA               6   COPY public.boursier (id, idet, idbourse) FROM stdin;
    public       postgres    false    202   �D       F          0    49757    chambre 
   TABLE DATA               5   COPY public.chambre (id, libelle, idbat) FROM stdin;
    public       postgres    false    204   �D       H          0    49762    etudiant 
   TABLE DATA               U   COPY public.etudiant (id, matricule, nom, prenom, datenaiss, email, tel) FROM stdin;
    public       postgres    false    206   E       J          0    49770    logement 
   TABLE DATA               5   COPY public.logement (id, libelle, idch) FROM stdin;
    public       postgres    false    208   �E       L          0    49775    loger 
   TABLE DATA               5   COPY public.loger (id, idet, idlogement) FROM stdin;
    public       postgres    false    210   �E       >          0    49737    non_boursier 
   TABLE DATA               9   COPY public.non_boursier (id, adresse, idet) FROM stdin;
    public       postgres    false    196   �E       N          0    49780    role 
   TABLE DATA               +   COPY public.role (id, libelle) FROM stdin;
    public       postgres    false    212   �E       P          0    49785    type_bourses 
   TABLE DATA               3   COPY public.type_bourses (id, libelle) FROM stdin;
    public       postgres    false    214   
F       R          0    49790    user 
   TABLE DATA               =   COPY public."user" (id, login, password, idrole) FROM stdin;
    public       postgres    false    216   GF       e           0    0    adresse_id_seq    SEQUENCE SET     <   SELECT pg_catalog.setval('public.adresse_id_seq', 1, true);
            public       postgres    false    197            f           0    0    batiment_id_seq    SEQUENCE SET     >   SELECT pg_catalog.setval('public.batiment_id_seq', 13, true);
            public       postgres    false    199            g           0    0    bourses_id_seq    SEQUENCE SET     <   SELECT pg_catalog.setval('public.bourses_id_seq', 3, true);
            public       postgres    false    201            h           0    0    boursier_id_seq    SEQUENCE SET     >   SELECT pg_catalog.setval('public.boursier_id_seq', 13, true);
            public       postgres    false    203            i           0    0    chambre_id_seq    SEQUENCE SET     =   SELECT pg_catalog.setval('public.chambre_id_seq', 19, true);
            public       postgres    false    205            j           0    0    etudiant_id_seq    SEQUENCE SET     >   SELECT pg_catalog.setval('public.etudiant_id_seq', 13, true);
            public       postgres    false    207            k           0    0    logement_id_seq    SEQUENCE SET     >   SELECT pg_catalog.setval('public.logement_id_seq', 1, false);
            public       postgres    false    209            l           0    0    loger_id_seq    SEQUENCE SET     ;   SELECT pg_catalog.setval('public.loger_id_seq', 1, false);
            public       postgres    false    211            m           0    0    role_id_seq    SEQUENCE SET     :   SELECT pg_catalog.setval('public.role_id_seq', 1, false);
            public       postgres    false    213            n           0    0    type_bourses_id_seq    SEQUENCE SET     A   SELECT pg_catalog.setval('public.type_bourses_id_seq', 2, true);
            public       postgres    false    215            o           0    0    user_id_seq    SEQUENCE SET     :   SELECT pg_catalog.setval('public.user_id_seq', 1, false);
            public       postgres    false    217            @   <   x���tJ,��M�+Qp40�2Gp���,<G.CC��ԙ���7u�24F2*�+F��� <2      B      x�3�41 N#�=... �      D      x�34�44�4�24��?�=... &�L      F   ;   x�34�t�H�M*JU0�4�24�sM8-�-\CNCc.CK���H�)�������� ��e      H   q   x�5�=�0�������3[Stp�*��%�Q�*(�{��������V�ڂ����"��Wm)��٦��m�*w]�����?珁ٳ�qq}[��Gk%��n�.��~�d      J      x������ � �      L      x������ � �      >      x�3�t/J�KQ.��y霆\1z\\\ a{�      N      x������ � �      P   -   x�3�tI���-H�+���S�2��2��sr�(IU������ (�u      R      x������ � �     