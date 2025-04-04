#define CLOVE_SUITE_NAME ObjParserTest
#include "clove-unit.h"
#define OBJPARSER_IMPLEMENTATION
#include "ObjParser.h"

CLOVE_TEST(TokenizerWithFourTokens) {

   std::string testString{"v -1.000000 1.000000 0.000000"};

   auto tokens = Tokenizer::Split(testString, ' ');

   CLOVE_SIZET_EQ(4, tokens.size());
   CLOVE_STRING_EQ(tokens[0].c_str(), "v");
   CLOVE_STRING_EQ(tokens[1].c_str(), "-1.000000");
   CLOVE_STRING_EQ(tokens[2].c_str(), "1.000000");
   CLOVE_STRING_EQ(tokens[3].c_str(), "0.000000");
}

CLOVE_TEST(Float3EqualsWithDifferentFloat3)
{
   Float3 f1{0.0f, 1.0f, 3.0f};
   Float3 f2{1.0f, 0.0f, 5.0f};

   CLOVE_IS_FALSE(f1 == f2);
}

CLOVE_TEST(Float3EqualsWithEqualFloat3)
{
   Float3 f1{0.0f, 1.0f, 3.0f};
   Float3 f2{0.0f, 1.0f, 3.0f};

   CLOVE_IS_TRUE(f1 == f2);
}

CLOVE_TEST(VertexEqualsWithDifferentVertexes)
{
   Float3 vn1{0.f, 0.f, 1.f};
   Float3 vpos1{1.0f, -1.0f, 0.0f};
   Float2 vuv1{1.0f, 0.0f};
   Vertex v1{vpos1, vn1, vuv1};

   Float3 vn2{0.f, 1.f, 5.f};
   Float3 vpos2{-4.0f, -1.0f, 0.0f};
   Float2 vuv2{1.0f, 3.0f};
   Vertex v2{vpos2, vn2, vuv2};

   CLOVE_IS_FALSE(v1 == v2);
}

CLOVE_TEST(VertexEqualsWithEqualVertexes)
{
   Float3 vn1{0.f, 0.f, 1.f};
   Float3 vpos1{1.0f, -1.0f, 0.0f};
   Float2 vuv1{1.0f, 0.0f};
   Vertex v1{vpos1, vn1, vuv1};

   Float3 vn2{0.f, 0.f, 1.f};
   Float3 vpos2{1.0f, -1.0f, 0.0f};
   Float2 vuv2{1.0f, 0.0f};
   Vertex v2{vpos2, vn2, vuv2};

   CLOVE_IS_TRUE(v1 == v2);
}

CLOVE_TEST(TriangleEqualsWithDifferentTriangles)
{
   Float3 vn{1.0f, 0.0f, 0.0f};

   // triangle 1
   // vertex 1
   Float3 pos_t1_v1{1.0f, -1.0f, 0.0f};
   Float2 uv_t1_v1{1.0f, 0.0f};
   Vertex t1_v1{pos_t1_v1, vn, uv_t1_v1};
   // vertex 2
   Float3 pos_t1_v2{-1.0f, -1.0f, 0.0f};
   Float2 uv_t1_v2{0.0f, 0.0f};
   Vertex t1_v2{pos_t1_v2, vn, uv_t1_v2};
   // vertex 3
   Float3 pos_t1_v3{-1.0f, 1.0f, 0.0f};
   Float2 uv_t1_v3{0.0f, 1.0f};
   Vertex t1_v3{pos_t1_v3, vn, uv_t1_v3};

   // triangle 2
   // vertex 1
   Float3 pos_t2_v1{1.0f, 1.0f, 0.0f};
   Float2 uv_t2_v1{1.0f, 1.0f};
   Vertex t2_v1{pos_t2_v1, vn, uv_t2_v1};
   // vertex 2
   Float3 pos_t2_v2{1.0f, -1.0f, 0.0f};
   Float2 uv_t2_v2{1.0f, 0.0f};
   Vertex t2_v2{pos_t2_v2, vn, uv_t2_v2};
   // vertex 3
   Float3 pos_t2_v3{-1.0f, 1.0f, 0.0f};
   Float2 uv_t2_v3{0.0f, 1.0f};
   Vertex t2_v3{pos_t2_v3, vn, uv_t2_v3};

   Triangle t1{t1_v1, t1_v2, t1_v3};
   Triangle t2{t2_v1, t2_v2, t2_v3};

   CLOVE_IS_FALSE(t1 == t2);
}

CLOVE_TEST(TriangleEqualsWithEqualTriangles)
{
   Float3 vn{1.0f, 0.0f, 0.0f};

   // triangle 1
   // vertex 1
   Float3 pos_t1_v1{1.0f, -1.0f, 0.0f};
   Float2 uv_t1_v1{1.0f, 0.0f};
   Vertex t1_v1{pos_t1_v1, vn, uv_t1_v1};
   // vertex 2
   Float3 pos_t1_v2{-1.0f, -1.0f, 0.0f};
   Float2 uv_t1_v2{0.0f, 0.0f};
   Vertex t1_v2{pos_t1_v2, vn, uv_t1_v2};
   // vertex 3
   Float3 pos_t1_v3{-1.0f, 1.0f, 0.0f};
   Float2 uv_t1_v3{0.0f, 1.0f};
   Vertex t1_v3{pos_t1_v3, vn, uv_t1_v3};

   // triangle 2
   // vertex 1
   Float3 pos_t2_v1{1.0f, -1.0f, 0.0f};
   Float2 uv_t2_v1{1.0f, 0.0f};
   Vertex t2_v1{pos_t2_v1, vn, uv_t2_v1};
   // vertex 2
   Float3 pos_t2_v2{-1.0f, -1.0f, 0.0f};
   Float2 uv_t2_v2{0.0f, 0.0f};
   Vertex t2_v2{pos_t2_v2, vn, uv_t2_v2};
   // vertex 3
   Float3 pos_t2_v3{-1.0f, 1.0f, 0.0f};
   Float2 uv_t2_v3{0.0f, 1.0f};
   Vertex t2_v3{pos_t2_v3, vn, uv_t2_v3};

   Triangle t1{t1_v1, t1_v2, t1_v3};
   Triangle t2{t2_v1, t2_v2, t2_v3};

   CLOVE_IS_TRUE(t1 == t2);
}

CLOVE_TEST(ObjParserWithInvalidPath)
{
   Obj obj;
   ObjParser objParser;

   CLOVE_IS_FALSE(objParser.TryParseObj("", obj));
}

CLOVE_TEST(ObjParserWithCorrectPath)
{
   std::string objPath{CLOVE_EXEC_BASE_PATH()};
   objPath += "/resources/quad.obj";

   Obj obj;
   ObjParser objParser;
   
   // read successful
   CLOVE_IS_TRUE(objParser.TryParseObj(objPath, obj)); 

   // expected size 2
   CLOVE_INT_EQ(obj.triangles.size(), 2);

   // same for every vertex
   Float3 vn{0.f, 0.f, 1.f};

   // triangle 1
   // vertex 1
   Float3 pos_t1_v1{1.0f, -1.0f, 0.0f};
   Float2 uv_t1_v1{1.0f, 0.0f};
   Vertex t1_v1{pos_t1_v1, vn, uv_t1_v1};
   // vertex 2
   Float3 pos_t1_v2{-1.0f, -1.0f, 0.0f};
   Float2 uv_t1_v2{0.0f, 0.0f};
   Vertex t1_v2{pos_t1_v2, vn, uv_t1_v2};
   // vertex 3
   Float3 pos_t1_v3{-1.0f, 1.0f, 0.0f};
   Float2 uv_t1_v3{0.0f, 1.0f};
   Vertex t1_v3{pos_t1_v3, vn, uv_t1_v3};

   // triangle 2
   // vertex 1
   Float3 pos_t2_v1{1.0f, 1.0f, 0.0f};
   Float2 uv_t2_v1{1.0f, 1.0f};
   Vertex t2_v1{pos_t2_v1, vn, uv_t2_v1};
   // vertex 2
   Float3 pos_t2_v2{1.0f, -1.0f, 0.0f};
   Float2 uv_t2_v2{1.0f, 0.0f};
   Vertex t2_v2{pos_t2_v2, vn, uv_t2_v2};
   // vertex 3
   Float3 pos_t2_v3{-1.0f, 1.0f, 0.0f};
   Float2 uv_t2_v3{0.0f, 1.0f};
   Vertex t2_v3{pos_t2_v3, vn, uv_t2_v3};

   Triangle t1{t1_v1, t1_v2, t1_v3};
   Triangle t2{t2_v1, t2_v2, t2_v3};

   // triangle 1
   //    vertex 1
   //       position
   CLOVE_FLOAT_EQ(obj.triangles[0].v1.position.a, pos_t1_v1.a);
   CLOVE_FLOAT_EQ(obj.triangles[0].v1.position.b, pos_t1_v1.b);
   CLOVE_FLOAT_EQ(obj.triangles[0].v1.position.c, pos_t1_v1.c);
   //       normal
   CLOVE_FLOAT_EQ(obj.triangles[0].v1.normal.a, vn.a);
   CLOVE_FLOAT_EQ(obj.triangles[0].v1.normal.b, vn.b);
   CLOVE_FLOAT_EQ(obj.triangles[0].v1.normal.c, vn.c);
   //       uv
   CLOVE_FLOAT_EQ(obj.triangles[0].v1.uv.a, uv_t1_v1.a);
   CLOVE_FLOAT_EQ(obj.triangles[0].v1.uv.b, uv_t1_v1.b);
   //    vertex 2
   //       position
   CLOVE_FLOAT_EQ(obj.triangles[0].v2.position.a, pos_t1_v2.a);
   CLOVE_FLOAT_EQ(obj.triangles[0].v2.position.b, pos_t1_v2.b);
   CLOVE_FLOAT_EQ(obj.triangles[0].v2.position.c, pos_t1_v2.c);
   //       normal
   CLOVE_FLOAT_EQ(obj.triangles[0].v2.normal.a, vn.a);
   CLOVE_FLOAT_EQ(obj.triangles[0].v2.normal.b, vn.b);
   CLOVE_FLOAT_EQ(obj.triangles[0].v2.normal.c, vn.c);
   //       uv
   CLOVE_FLOAT_EQ(obj.triangles[0].v2.uv.a, uv_t1_v2.a);
   CLOVE_FLOAT_EQ(obj.triangles[0].v2.uv.b, uv_t1_v2.b);
   //    vertex 3
   //       position
   CLOVE_FLOAT_EQ(obj.triangles[0].v3.position.a, pos_t1_v3.a);
   CLOVE_FLOAT_EQ(obj.triangles[0].v3.position.b, pos_t1_v3.b);
   CLOVE_FLOAT_EQ(obj.triangles[0].v3.position.c, pos_t1_v3.c);
   //       normal
   CLOVE_FLOAT_EQ(obj.triangles[0].v3.normal.a, vn.a);
   CLOVE_FLOAT_EQ(obj.triangles[0].v3.normal.b, vn.b);
   CLOVE_FLOAT_EQ(obj.triangles[0].v3.normal.c, vn.c);
   //       uv
   CLOVE_FLOAT_EQ(obj.triangles[0].v3.uv.a, uv_t1_v3.a);
   CLOVE_FLOAT_EQ(obj.triangles[0].v3.uv.b, uv_t1_v3.b);
   // triangle 2
   //    vertex 1
   //       position
   CLOVE_FLOAT_EQ(obj.triangles[1].v1.position.a, pos_t2_v1.a);
   CLOVE_FLOAT_EQ(obj.triangles[1].v1.position.b, pos_t2_v1.b);
   CLOVE_FLOAT_EQ(obj.triangles[1].v1.position.c, pos_t2_v1.c);
   //       normal
   CLOVE_FLOAT_EQ(obj.triangles[1].v1.normal.a, vn.a);
   CLOVE_FLOAT_EQ(obj.triangles[1].v1.normal.b, vn.b);
   CLOVE_FLOAT_EQ(obj.triangles[1].v1.normal.c, vn.c);
   //       uv
   CLOVE_FLOAT_EQ(obj.triangles[1].v1.uv.a, uv_t2_v1.a);
   CLOVE_FLOAT_EQ(obj.triangles[1].v1.uv.b, uv_t2_v1.b);
   //    vertex 2
   //       position
   CLOVE_FLOAT_EQ(obj.triangles[1].v2.position.a, pos_t2_v2.a);
   CLOVE_FLOAT_EQ(obj.triangles[1].v2.position.b, pos_t2_v2.b);
   CLOVE_FLOAT_EQ(obj.triangles[1].v2.position.c, pos_t2_v2.c);
   //       normal
   CLOVE_FLOAT_EQ(obj.triangles[1].v2.normal.a, vn.a);
   CLOVE_FLOAT_EQ(obj.triangles[1].v2.normal.b, vn.b);
   CLOVE_FLOAT_EQ(obj.triangles[1].v2.normal.c, vn.c);
   //       uv
   CLOVE_FLOAT_EQ(obj.triangles[1].v2.uv.a, uv_t2_v2.a);
   CLOVE_FLOAT_EQ(obj.triangles[1].v2.uv.b, uv_t2_v2.b);
   //    vertex 3
   //       position
   CLOVE_FLOAT_EQ(obj.triangles[1].v3.position.a, pos_t2_v3.a);
   CLOVE_FLOAT_EQ(obj.triangles[1].v3.position.b, pos_t2_v3.b);
   CLOVE_FLOAT_EQ(obj.triangles[1].v3.position.c, pos_t2_v3.c);
   //       normal
   CLOVE_FLOAT_EQ(obj.triangles[1].v3.normal.a, vn.a);
   CLOVE_FLOAT_EQ(obj.triangles[1].v3.normal.b, vn.b);
   CLOVE_FLOAT_EQ(obj.triangles[1].v3.normal.c, vn.c);
   //       uv
   CLOVE_FLOAT_EQ(obj.triangles[1].v3.uv.a, uv_t2_v3.a);
   CLOVE_FLOAT_EQ(obj.triangles[1].v3.uv.b, uv_t2_v3.b);
}
